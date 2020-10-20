use std::collections::HashSet;

impl Solution {
    // Don't get too invested with lifetime.
    pub const morse: [&'static str; 26] = [
        ".-","-...","-.-.","-..",".","..-.","--.","....","..",
        ".---","-.-",".-..","--","-.","---",".--.","--.-",".-.",
        "...","-","..-","...-",".--","-..-","-.--","--.."
    ];
        
    pub fn unique_morse_representations(words: Vec<String>) -> i32 {
        let mut h: HashSet<String> = HashSet::with_capacity(words.len());
        
        for word in words {
            // transform into morse code and add into hashset
            let code = word
                        .chars()
                        .map(|x| Solution::morse[(x.to_digit(36).expect("") - 10) as usize])
                        .collect::<Vec<&str>>()
                        .join("");
            h.insert(code);
        }
        // return hashset length.
        h.len() as i32
    }
}
