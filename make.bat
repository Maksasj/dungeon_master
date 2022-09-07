gcc -o dist/main.elf src/main.c
objcopy -O binary dist/main.elf dist/game.gba