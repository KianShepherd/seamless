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