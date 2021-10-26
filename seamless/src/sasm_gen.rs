#![allow(unused_mut)]
use std::fs;
use std::slice::Iter;
use crate::ast::{Expression, Function, Statement};

pub fn create_asm_text(functions: &mut Iter<Function>) -> String {
    let mut out = String::new();
    for function in functions {
        out.push_str(&parse_function(function));
    }

    out
}

pub fn create_asm(tree: &mut Iter<Function>, outfile: & String) {
    let mut out = create_asm_text(tree);
    fs::write(&outfile, &out).expect("Failed to write to file");
}


pub fn parse_expressions(expressions: &Vec<Expression>) -> String {
    let mut out = String::new();
    for index in 0..expressions.len() {
        let expr_type: &str = &expressions[index].get_type();
        match expr_type {
            "integer literal" => { out = out + &expressions[index].get_text(); }
            _ => return "".to_string(),
        }

    }
    out
}

fn parse_statements(statements: &Vec<Statement>) -> String  {
    let mut out = String::new();
    for statement in statements {
        if statement.get_type() == "return keyword" {
            out.push_str(&("SET 0, ".to_string() + &parse_expressions(statement.get_expressions()) + "\n"));
            out.push_str("RET\n");
        }
    }
    out
}


pub fn parse_function(func: &Function) -> String {
    let mut out = String::new();
    out.push_str(&parse_statements(func.get_statements()));

    out
}