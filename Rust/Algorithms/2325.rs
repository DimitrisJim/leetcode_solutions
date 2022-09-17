use std::collections::HashMap;

impl Solution {
    pub fn decode_message(key: String, message: String) -> String {
        let mut chars = HashMap::new();
        let ascii_lower = String::from("abcdefghijklmnopqrstuvwxyz");
        let mut ascii_it = ascii_lower.chars();
        
        for ch in key.chars() {
            if !chars.contains_key(&ch) {
                if ch != ' ' {
                    // guarantees
                    chars.insert(ch, ascii_it.next().unwrap());
                }
            }
        }
        chars.insert(' ', ' ');
        
        let mut res = String::new();
        for ch in message.chars() {
            // always ok to unwrap
            res.push(*chars.get(&ch).unwrap());
        }
        res
    }
}