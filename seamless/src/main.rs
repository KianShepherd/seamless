#![allow(dead_code)]

extern crate regex;
use std::env;
use crate::ast::AstNode;

mod tokenizer;
mod token;
mod ast;
mod parser;
mod sasm_gen;

fn main() {
    let args: Vec<String> = env::args().collect();
    let mut filename = "./test_files/test.seam".to_string();
    if args.len() >= 2 {
        match args.get(1) {
            Some(arg) => { filename = arg.to_string() },
            None => (),
        }
    }
    let len = filename.len();
    let assembly_filename = String::from(&filename)[0..len - 4].to_string() + &"sasm".to_string();
    let tokens = &mut tokenizer::get_tokens(filename);

    // tokens debug
    for tok in tokens.iter() {
        println!("{} : {}", tok.get_type(), tok.get_text());
    }

    let mut functions: Vec<AstNode> = vec![];

    loop {
        let node = parser::parse_function(tokens);
        functions.push(node);

        if (tokens.len() == 0){
            break;
        }
    }

    //ast debug
    for x in functions.iter() {
        println!("{}", x.to_string());
    }

    // Create Assembly file
    sasm_gen::create_asm(&mut functions.iter(), &assembly_filename);
}