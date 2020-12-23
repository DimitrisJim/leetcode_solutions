use std::collections::HashSet;

impl Solution {
    pub fn remove_palindrome_sub(s: String) -> i32 {
        let len = s.len();
        if s.len() == 0 {
            return 0;
        }
        // Check if the full string is palindromic
        let slice_one = &s[0..len / 2];
        let left = len / 2 + if len % 2 == 1 { 1 } else { 0 };
        let slice_two: &String = &s[left..len].chars().rev().collect();
        if slice_one == slice_two {
            return 1;
        }

        let s: HashSet<_> = s.chars().collect();
        s.len() as i32
    }
}
