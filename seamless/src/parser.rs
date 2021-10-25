use crate::ast;
use crate::ast::AstNode;
use crate::token::Token;

// <exp> ::= <int>
pub fn parse_expression(tokens: &mut std::vec::Vec<Token>) -> std::vec::Vec<AstNode>{
    let mut nodes = vec![];
    let tok = Token::new(tokens[0].get_type(), tokens[0].get_text());
    tokens.remove(0);
    let _type: &str = &tok.get_type();
    match _type {
        "integer literal" => { let mut node = AstNode::new("expression".to_string()); node.set_expression(ast::Expression::new(tok.get_type(), tok.get_text())); nodes.push(node); },
        _ => panic!("Invalid type for expression"),
    }
    nodes
}

// <statement> ::= "return" <exp> ";"
fn parse_statement(tokens: &mut std::vec::Vec<Token>) -> AstNode {
    let tok = Token::new(tokens[0].get_type(), tokens[0].get_text());
    tokens.remove(0);
    if tok.get_type() != "return keyword" {
        panic!("Return keyword expected");
    }
    let mut node = AstNode::new("statement".to_string());
    let mut statement = ast::Statement::new("return keyword".to_string());

    statement.add_expression(&mut parse_expression(tokens));
    node.set_statement(statement);

    let tok = Token::new(tokens[0].get_type(), tokens[0].get_text());
    tokens.remove(0);
    if tok.get_type() != "semicolon" {
        panic!("Semicolon expected");
    }

    node
}

// <function> ::= "int" <id> "(" ")" "{" <statement> "}"
pub fn parse_function(tokens: &mut std::vec::Vec<Token>) -> AstNode {
    let tok = Token::new(tokens[0].get_type(), tokens[0].get_text());
    tokens.remove(0);
    if tok.get_type() != "int keyword" {
        panic!("Function type identifier expected");
    }

    let tok = Token::new(tokens[0].get_type(), tokens[0].get_text());
    tokens.remove(0);
    if tok.get_type() != "identifier" {
        panic!("Function name expected");
    }
    let identifier = tok.get_text();

    let tok = Token::new(tokens[0].get_type(), tokens[0].get_text());
    tokens.remove(0);
    if tok.get_type() != "open parenthesis" {
        panic!("( expected");
    }

    let tok = Token::new(tokens[0].get_type(), tokens[0].get_text());
    tokens.remove(0);
    if tok.get_type() != "close parenthesis" {
        panic!(") expected");
    }

    let tok = Token::new(tokens[0].get_type(), tokens[0].get_text());
    tokens.remove(0);
    if tok.get_type() != "open brace" {
        panic!("{{ expected");
    }

    let mut node = AstNode::new("function".to_string());
    let mut function = ast::Function::new(identifier);
    let mut statement;
    loop {
        statement = parse_statement(tokens);

        match statement.get_statement() {
            Some(_statement) => { if _statement.get_type() == "return keyword" {
                break;
            }},
            None => { break; },
        }
        function.add_statement(statement);


    }
    function.add_statement(statement);
    node.set_function(function);
    if tokens.len() == 0 {
        panic!("}} expected");
    }

    let tok = Token::new(tokens[0].get_type(), tokens[0].get_text());
    tokens.remove(0);
    if tok.get_type() != "close brace" {
        panic!("}} expected");
    }

    node
}
