use crate::ast;
use crate::ast::AstNode;
use crate::token::TokenStack;

// <exp> ::= <int>
pub fn parse_expression(tokens: &mut TokenStack) -> std::vec::Vec<AstNode>{
    let mut nodes = vec![];
    let tok = tokens.pop();

    let _type: &str = &tok.get_type();
    match _type {
        "integer literal" => { let mut node = AstNode::new("expression".to_string()); node.set_expression(ast::Expression::new(tok.get_type(), tok.get_text())); nodes.push(node); },
        _ => panic!("Invalid type for expression"),
    }
    nodes
}

// <statement> ::= "return" <exp> ";"
fn parse_statement(tokens: &mut TokenStack) -> AstNode {
    tokens.pop_check("return keyword");

    let mut node = AstNode::new("statement".to_string());
    let mut statement = ast::Statement::new("return keyword".to_string());

    statement.add_expression(&mut parse_expression(tokens));
    node.set_statement(statement);

    tokens.pop_check("semicolon");

    node
}

// <function> ::= "int" <id> "(" ")" "{" <statement> "}"
pub fn parse_function(tokens: &mut TokenStack) -> AstNode {
    tokens.pop_check("int keyword");
    let identifier = tokens.pop_check("identifier").get_text();
    tokens.pop_check("open parenthesis");
    tokens.pop_check("close parenthesis");
    tokens.pop_check("open brace");

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

    tokens.pop_check("close brace");

    node
}
