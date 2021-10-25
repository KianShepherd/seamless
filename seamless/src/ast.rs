pub struct AstNode {
    node_type: String,
    expression: Option<Expression>,
    statement: Option<Statement>,
    function: Option<Function>
}

pub struct Expression {
    exp_type: String,
    exp_text: String
}

pub struct Statement {
    statement_type: String,
    body: Vec<AstNode>
}

pub struct Function {
    id: String,
    body: Vec<AstNode>
}

impl AstNode {
    pub fn new(_node_type: String,) -> AstNode {
        AstNode {
            node_type:  _node_type,
            expression: None,
            statement:  None,
            function:   None
        }
    }

    pub fn set_expression(&mut self, exp: Expression)   { self.expression = Some(exp); }
    pub fn set_statement(&mut self, stat: Statement)    { self.statement = Some(stat); }
    pub fn set_function(&mut self, func: Function)      { self.function = Some(func); }

    pub fn get_expression(&self) -> &Option<Expression> { &self.expression }
    pub fn get_statement(&self)  -> &Option<Statement>  { &self.statement }
    pub fn get_function(&self)   -> &Option<Function>   { &self.function }
    pub fn get_type(&self)       -> &String             { &self.node_type }

    pub fn to_string(&self) -> String {
        let _type: &str = &self.node_type;
        match _type {
            "expression" => {
                match &self.expression {
                    Some(exp) => {
                        format!("{}", &exp.get_text())
                    },
                    None => "".to_string()
                }
            },
            "statement" => {
                match &self.statement {
                    Some(stat) => {
                        format!("{}", &stat.to_string())
                    },
                    None => "".to_string()
                }
            },
            "function" => {
                match &self.function {
                    Some(func) => {
                        format!("{}", &func.to_string())
                    },
                    None => "".to_string()
                }
            },
            &_ => {
                "".to_string()
            }
        }
    }
}

impl Function {
    pub fn new(_id: String) -> Function {
        Function {
            id: _id,
            body: vec![],
        }
    }

    pub fn get_id(&self) -> String { String::from(&self.id.to_string()) }
    pub fn add_statement(&mut self, statement: AstNode) { &self.body.push(statement); }
    pub fn to_string(&self) -> String {
        let mut out: String = "Function ".to_string() + &self.id.to_string() + &":\n".to_string();
        out = out + "    body:\n    ";
        for stat in &self.body {
            match stat.get_statement() {
                Some(statement) => { out = out + &statement.to_string() + "\n"; },
                None => {},
            }

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
    pub fn add_expression(&mut self, expr: &mut Vec<AstNode>) { &self.body.append(expr); }
    pub fn to_string(&self) -> String {
        let mut out: String = "    Return ".to_string();
        for expr in &self.body {
            match expr.get_expression() {
                Some(expression) => { out = out + &expression.to_string() + "\n"; },
                None => {},
            }
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