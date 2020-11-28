use std::iter::FromIterator;

impl Solution {
    pub fn remove_duplicates(s: String) -> String {
        let mut stack = Vec::new();
        for e in s.chars() {
            let len = stack.len();
            if len > 0 && stack[len - 1] == e {
                stack.pop();
            } else {
                stack.push(e);
            }
        }
        String::from_iter(stack)
    }
}
