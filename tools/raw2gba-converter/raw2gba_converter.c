//USE MinGW!

#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

#define RAW_TYPE ".raw"
#define HEADER_TYPE ".h"

#define RAW_TYPE_NAME_SIZE 4
#define HEADER_TYPE_NAME_SIZE 2

#define BYTES_PER_LINE 11

#define UPPERCASE_LETTER_DIFFERENCE 32

int32_t check_format(char *file_name) {
    size_t file_name_length = strlen(file_name);

    for (int32_t index = 0; index < RAW_TYPE_NAME_SIZE; ++index) {
        if (file_name[file_name_length - RAW_TYPE_NAME_SIZE + index] != RAW_TYPE[index]) {
            printf("File \"%s\" cannot be converted! (file type must be .raw)\n", file_name);
            return 0;
        }
    }

    return 1;
}

int32_t get_file_length(FILE *source) {
    fseek(source, 0, SEEK_END);
    int32_t length = ftell(source);
    fseek(source, 0, SEEK_SET);

    return length;
}

void to_uppercase(char *str) {
    for (int32_t index = 0; str[index] != '\0'; ++index) {
        if (str[index] >= 'a' && str[index] <= 'z') {
            str[index] -= UPPERCASE_LETTER_DIFFERENCE;
        }
    }
}

char *concatinate_strings(char *destination, char *source) {
    size_t initial_destination_length = strlen(destination);

    for (int32_t index = 0; index < strlen(source); ++index) {
        destination[initial_destination_length + index] = source[index];
    }

    destination[initial_destination_length + strlen(source)] = '\0';

    return destination;
}

void convert(FILE *source, char *file_name) {
    int32_t file_length = get_file_length(source);

    signed char *bytes = malloc(file_length * sizeof(signed char));
    fread(bytes, file_length, 1, source);

    FILE *header_file;
    size_t file_name_length = strlen(file_name);

    char *base = (char *) malloc((file_name_length + 1) * sizeof(char));
    strcpy(base, file_name);
    base[file_name_length - RAW_TYPE_NAME_SIZE] = '\0';

    char *header_file_name = (char *)malloc((file_name_length - HEADER_TYPE_NAME_SIZE) * sizeof(char));
    strcpy(header_file_name, base);
    header_file_name = concatinate_strings(header_file_name, HEADER_TYPE);

    header_file = fopen(header_file_name, "w");

    if (header_file == NULL) {
        printf("Unable to create .h file\n");
        return;
    }

    to_uppercase(base);

    fprintf(header_file, "#include \"../include/types.h\"\n\n");
    fprintf(header_file, "#define _%s_BYTES_ %d\n\n", base, file_length);
    fprintf(header_file, "i8 %s [] = {\n", base);

    int32_t byte_element_at_line_counter = 1;
    fprintf(header_file, "\t");
    fprintf(header_file, "0x%02X", bytes[0] & 0xff);

    for (int32_t index = 1; index < file_length; ++index) {
        fprintf(header_file, ", ");

        if (byte_element_at_line_counter > BYTES_PER_LINE) {
            byte_element_at_line_counter = 0;
            fprintf(header_file, "\n");
            fprintf(header_file, "\t");
        }

        ++byte_element_at_line_counter;
        fprintf(header_file, "0x%02X", bytes[index] & 0xff);
    }
    
    fprintf(header_file, "\n};\n");

    fclose(header_file);
    free(bytes);
    free(base);
    free(header_file_name);
}

int32_t main(int32_t argc, char *argv[]) {
    if (argc <= 1) {
        printf("There must be at least one argument");
        return 0;
    }

    FILE *source;

    for (int32_t index = 1; index < argc; ++index) {
        if (check_format(argv[index])) {
            source = fopen(argv[index], "r");

            if (source == NULL) {
                printf("Cannot open file with name \"%s\"\n", argv[index]);
            } else {
                convert(source, argv[index]);
                fclose(source);
            }
        }
    }

    return 0; 
}
