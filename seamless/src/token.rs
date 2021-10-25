// used in creating the regex for finding tokens
pub struct TokenBuilder {
    tok_type: String,
    tok_regex: String,
}

// Final token struct that is output
pub struct Token {
    tok_type: String,
    matched_text: String,
}

pub struct TokenStack {
    stack: Vec<Token>
}

impl TokenStack {
    pub fn new() -> TokenStack {
        TokenStack {
            stack: vec![],
        }
    }

    pub fn add(&mut self, token: Token) {
        &self.stack.push(token);
    }

    pub fn pop(&mut self) -> Token {
        if self.stack.len() <= 0{
            panic!("No tokens are left on the stack")
        }
        
        let token = Token::new(self.stack.get(0).unwrap().get_type(), self.stack.get(0).unwrap().get_text());
        &self.stack.remove(0);

        token
    }

    pub fn len(&self) -> usize {
        self.stack.len()
    }

    pub fn get_stack(&self) -> &Vec<Token> {
        &self.stack
    }

    pub fn pop_check(&mut self, comparison: &str) -> Token {
        if self.stack.len() <= 0{
            panic!("No tokens are left on the stack")
        }
        
        let token = Token::new(self.stack.get(0).unwrap().get_type(), self.stack.get(0).unwrap().get_text());
        &self.stack.remove(0);
        if (token.get_type() != comparison) {
            panic!("Unexpected token {} found.", token.get_type())
        }

        token
    }

    pub fn peek(&self) -> Token {
        if self.stack.len() <= 0{
            panic!("No tokens are left on the stack")
        }
        Token::new(self.stack.get(0).unwrap().get_type(), self.stack.get(0).unwrap().get_text())
    }
}

impl Token {
    pub fn new(typ: String, tex: String) -> Token {
        Token {
            tok_type: typ,
            matched_text: tex.trim().to_string(),
        }
    }

    pub fn get_type(&self) -> String { String::from(&self.tok_type.to_string()) }
    pub fn get_text(&self) -> String { String::from(&self.matched_text.to_string()) }
}

impl TokenBuilder {
    pub fn new(typ: String, reg: String) -> TokenBuilder {
        TokenBuilder {
            tok_type: typ,
            tok_regex: reg,
        }
    }

    pub fn get_type(&self)  -> String { String::from(&self.tok_type.to_string()) }
    pub fn get_regex(&self) -> String { String::from(&self.tok_regex) }
}