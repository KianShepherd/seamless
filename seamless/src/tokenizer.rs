use regex::Regex;
use crate::token::TokenBuilder;
use crate::token::Token;
use std::fs;

// Creates vector of TokenBuilders for each kind of token that is being looked for
// sorted by priority they should be matched
fn create_token_array() -> std::vec::Vec<TokenBuilder> {
    let mut tokens = vec![];
    tokens.push(TokenBuilder::new("open brace".to_string(), "\\{".to_string()));
    tokens.push(TokenBuilder::new("close brace".to_string(), "\\}".to_string()));
    tokens.push(TokenBuilder::new("open parenthesis".to_string(), "\\(".to_string()));
    tokens.push(TokenBuilder::new("close parenthesis".to_string(), "\\)".to_string()));
    tokens.push(TokenBuilder::new("semicolon".to_string(), ";".to_string()));
    tokens.push(TokenBuilder::new("int keyword".to_string(), "int".to_string()));
    tokens.push(TokenBuilder::new("return keyword".to_string(), "return[\n\t\r ]".to_string()));
    tokens.push(TokenBuilder::new("identifier".to_string(), "[a-zA-Z]\\w*".to_string()));
    tokens.push(TokenBuilder::new("integer literal".to_string(), "[0-9]+".to_string()));
    tokens
}

// Builds regex string to match all token types in one go
fn regex_string_builder(tok_arr: std::vec::Vec<TokenBuilder>) -> String {
    let mut ret_str = "".to_string();
    for tok in tok_arr { ret_str = ret_str + "(" + &tok.get_regex() + ")|"; }
    // return all but last character to remove trailing '|'
    (&ret_str[0..ret_str.len() - 1]).to_string()
}

// Pass in file name
// Returns Vector of tokens found in file
pub fn get_tokens(file_name: String) -> std::vec::Vec<Token> {
    let builder_vector = create_token_array();
    let content = fs::read_to_string(file_name).expect("Unable to read file");
    let _re = Regex::new(&regex_string_builder(builder_vector)).unwrap();
    let mut re;
    let mut final_token_vector = vec![];

    // Get all tokens from input file as separate Strings
    // then build them into final token vector
    for cap in _re.captures_iter(&content) {
        for builder in create_token_array() {
            re = Regex::new(&builder.get_regex()).unwrap();
            if re.is_match(&cap[0]) { // builder matches current capture
                // create new Token and add it to the returning vector
                final_token_vector.push(Token::new(builder.get_type(), (&cap[0]).to_string()));
                // println!("{}", &cap[0]); // Debug Line
                break; // in case text matches multiple builders eg. int and identifier
            }
        }
    }

    final_token_vector
}