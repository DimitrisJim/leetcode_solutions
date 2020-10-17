impl Solution {
    pub fn remove_outer_parentheses(s: String) -> String {
        let mut res = String::from("");
        let mut depth: i32 = 0;
        for c in s.chars() {
            if c == '(' {
                if depth >= 1 {
                    res.push(c);
                }
                depth += 1;
            } else {
                depth -= 1;
                if depth >= 1 {
                    res.push(c);
                }
            }
        }
        res
    }
}
