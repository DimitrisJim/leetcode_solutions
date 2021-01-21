impl Solution {
    pub fn detect_capital_use(word: String) -> bool {
        if word.len() == 1 {
            return true;
        }
        let (upper, lower) = (char::is_uppercase, char::is_lowercase);
        let mut char_it = word.chars();
        match upper(char_it.next().unwrap()) {
            true => match upper(char_it.next().unwrap()) {
                true => char_it.all(upper),
                false => char_it.all(lower),
            },
            false => char_it.all(lower),
        }
    }
}
