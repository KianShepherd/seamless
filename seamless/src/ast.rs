#![allow(dead_code)]
pub struct Expression {
    exp_type: String,
    exp_text: String
}

pub struct Statement {
    statement_type: String,
    body: Vec<Expression>
}

pub struct Function {
    id: String,
    body: Vec<Statement>
}

impl Function {
    pub fn new(_id: String) -> Function {
        Function {
            id: _id,
            body: vec![],
        }
    }

    pub fn get_id(&self) -> String { String::from(&self.id.to_string()) }
    pub fn add_statement(&mut self, statement: Statement) { let _ = &self.body.push(statement); }
    pub fn get_statements(&self) -> &Vec<Statement> { &self.body }
    pub fn to_string(&self) -> String {
        let mut out: String = "Function ".to_string() + &self.id.to_string() + &":\n".to_string();
        out = out + "    body:\n    ";
        for statement in &self.body {
            out = out + &statement.to_string() + "\n";
        }
        String::from(out)
    }
}

impl Statement {
    pub fn new(statement_type: String) -> Statement {
        Statement {
            statement_type,
            body: vec![]
        }
    }

    pub fn get_type(&self) -> &String { &self.statement_type }
    pub fn add_expression(&mut self, expr: Expression) { let _ = &self.body.push(expr); }
    pub fn get_expressions(&self) -> &Vec<Expression> { &self.body }
    pub fn to_string(&self) -> String {
        let mut out: String = "    Return ".to_string();
        for expression in &self.body {
            out = out + &expression.to_string() + "\n";
        }
        String::from(out)
    }
}

impl Expression {
    pub fn new(_exp_type: String, _exp_text: String) -> Expression {
        Expression {
            exp_type: _exp_type,
            exp_text: _exp_text,
        }
    }

    pub fn get_type(&self) -> String { String::from(&self.exp_type.to_string()) }
    pub fn get_text(&self) -> String { String::from(&self.exp_text.to_string()) }

    pub fn to_string(&self) -> String {
        let out: String = String::from("".to_string() + &self.exp_text.to_string()) + &" <".to_string() + &self.exp_type.to_string() + &">".to_string();
        String::from(out)
    }
}