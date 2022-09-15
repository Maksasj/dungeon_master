use std::env;
use std::fs;

/*
$DEFINE RULE:
    $new :: {{TYPE}{WORD}{=}$KEY{(}{VALUE}{)}} => {
        TYPE stringify(WORD) = VALUE;
        TYPE* stringify(WORD)+_ptr = &stringify(WORD);
    }

var h = new Porinte(1165);

$DEFINE RULE:
    $new :: {=}$KEY{TYPE}{(}{VALUE}{)}} => {
        TYPE stringify(WORD)_v = VALUE;
        {_} = &stringify(WORD)_v
    }
*/

enum Token {
    Word,
    Sym,
}

fn no_space(x : String) -> String {
    x.replace(" ", "")
}

fn to_plain_vec(input: String) -> Vec<char> {
    let mut source = Vec::new();

    for c in input.chars() { 
        if c != '\n' && c != '\r'{
            source.push(c);
        }
    }

    source
}

struct MetaData {
    fileName: String,
}

struct File {
    content: Vec<char>,
    includes: Vec<File>,
    meta: MetaData,
}

fn find_all_includes(file: File) -> Vec<File> {
    let mut source: Vec<File> = Vec::new();

    let mut tmp: String = String::new();
    let mut tmpl: bool = false;
    for c in file.content.iter() {

         //C Macro
        if (*c == '#') {
            tmpl = true;
        }
        
        if tmpl == true {
            tmp.push(*c);
        }

        if tmpl == true && tmp == "#include" { //Found include
            println!("Found include");
        }
    }

    return source;
}

fn main() {
    println!("Preprocessor started");
    
    let args: Vec<String> = env::args().collect();

    let _a: Token = Token::Word;
    let _b: Token = Token::Sym;

    //Lets assert what user should provide preprocessor with atleast 2 arguments
    //assert_eq!(args.len(), 3);

    let mut rawSource: String = fs::read_to_string("test.c").expect("Error in reading source file");
    rawSource = no_space(rawSource);
    let mut source: Vec<char> = to_plain_vec(rawSource);

    let mut file: File = File { content: source, includes: Vec::new(), meta: MetaData {fileName: "test.c".to_string()}};
    let mut includes = find_all_includes(file);

    //for c in source.iter() {
    //    println!("{}", c);
    //}

    println!("Preprocessor finished");
}