use crate::ast;
use crate::ast::{Expression, Function, Statement};
use crate::token::TokenStack;

// <exp> ::= <int>
pub fn parse_expression(tokens: &mut TokenStack) -> Expression {
    let tok = tokens.pop();

    let _type: &str = &tok.get_type();
    match _type {
        "integer literal" => { ast::Expression::new(tok.get_type(), tok.get_text()) },
        _ => panic!("Invalid type for expression"),
    }
}

// <statement> ::= "return" <exp> ";"
fn parse_statement(tokens: &mut TokenStack) -> Statement {
    tokens.pop_check("return keyword");

    let mut statement = ast::Statement::new("return keyword".to_string());
    while tokens.peek(0).get_type() != "semicolon" {
        statement.add_expression(parse_expression(tokens));
    }


    tokens.pop_check("semicolon");

    statement
}

// <function> ::= "int" <id> "(" ")" "{" <statement> "}"
pub fn parse_function(tokens: &mut TokenStack) -> Function {
    tokens.pop_check("int keyword");
    let identifier = tokens.pop_check("identifier").get_text();
    tokens.pop_check("open parenthesis");
    tokens.pop_check("close parenthesis");
    tokens.pop_check("open brace");

    let mut function = ast::Function::new(identifier);
    let mut statement;
    loop {
        statement = parse_statement(tokens);

        if statement.get_type() == "return keyword" {
            break;
        }
        function.add_statement(statement);
    }
    function.add_statement(statement);

    tokens.pop_check("close brace");

    function
}
