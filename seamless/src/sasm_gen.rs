#![allow(unused_mut)]
use crate::ast;
use std::fs;

fn parse_next(tree: &mut std::slice::Iter<ast::AstNode>, out: &mut String) {
    let next = tree.next();
    let mut _type_check = String::new();
    match next {
        Some(x) => _type_check = String::from(x.get_type()),
        None => return,
    }
    let type_check: &str = &_type_check;
    match type_check {
        "expression"    => parse_type_of_expression(&next, tree, out),
        "statement"     => { parse_next(tree, out); out.push_str("\nCLS") },
        "function"      => out.push_str(&parse_function(next)),
        _ => return,
    }
    parse_next(tree, out);
}

fn parse_type_of_expression(node: &Option<&ast::AstNode>, tree: &mut std::slice::Iter<ast::AstNode>, out: &mut String) {
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
    parse_next(tree, &mut out);
    out
}

pub fn create_asm(tree: &mut std::slice::Iter<ast::AstNode>, outfile: & String) {
    let mut out = create_asm_text(tree);
    fs::write(&outfile, &out).expect("Failed to write to file");
}


fn parse_expression(node: &Option<&ast::AstNode>) -> String {
    let mut out = String::new();
    match node {
        Some(x) => {
            match x.get_expression() {
                Some(y) => {
                    out.push_str("SET 0, ");
                    out.push_str(&y.get_text());
                    out
                },
                None => out
            }
        },
        None => out
    }
}
/*
fn parse_statement(node: Option<&ast::AstNode>) -> String  {
    let mut out = String::new();
    out.push_str();
    out.push_str("    ret\n");
    return out;
}
*/
fn parse_function(node: Option<&ast::AstNode>) -> String {
    let mut out = String::new();
    match node {
        Some(x) => {
            match x.get_function() {
                Some(y) => {
                    out
                },
                None => out
            }
        },
        None => out
    }
}