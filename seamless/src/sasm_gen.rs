#![allow(unused_mut)]
use crate::ast;
use std::fs;

pub fn parse_type_of_expression(node: &Option<&ast::AstNode>, out: &mut String) {
    match node {
        Some(x) => {
            match x.get_expression() {
                Some(y) => {
                    let string: &str = &y.get_type();
                    match string {
                        _ => out.push_str(&parse_expression(&node)),
                    }
                },
                None => return,
            }
        },
        None => return,
    }
}

pub fn create_asm_text(tree: &mut std::slice::Iter<ast::AstNode>) -> String {
    let mut out = String::new();
    for function in tree {
        out.push_str(&parse_function(Some(function)));
    }

    out
}

pub fn create_asm(tree: &mut std::slice::Iter<ast::AstNode>, outfile: & String) {
    let mut out = create_asm_text(tree);
    fs::write(&outfile, &out).expect("Failed to write to file");
}


pub fn parse_expression(node: &Option<&ast::AstNode>) -> String {
    let mut out = String::new();
    match node {
        Some(x) => {
            match x.get_expression() {
                Some(y) => {
                    out.push_str("SET 0, ");
                    out.push_str(&y.get_text());
                    out.push_str("\n");
                    out
                },
                None => out
            }
        },
        None => out
    }
}

fn parse_statement(node: Option<&ast::AstNode>) -> String  {
    let mut out = String::new();
    match node {
        Some(x) => {
            match x.get_statement() {
                Some(statement) => {
                    let expressions = statement.get_expressions();
                    for expression in expressions.iter() {
                        parse_type_of_expression(&Some(expression), &mut out)
                    }
                    out.push_str("RET\n");
                    out
                },
                None => out
            }
        },
        None => out
    }
}

pub fn parse_function(node: Option<&ast::AstNode>) -> String {
    let mut out = String::new();
    match node {
        Some(x) => {
            match x.get_function() {
                Some(func) => {
                    let statements = func.get_statements();
                    for statement in statements.iter() {
                        out.push_str(&parse_statement(Some(&statement)));
                    }
                    out
                },
                None => out
            }
        },
        None => out
    }
}