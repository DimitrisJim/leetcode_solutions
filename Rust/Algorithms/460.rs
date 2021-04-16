use std::cmp::min;

impl Solution {
    pub fn min_operations(s: String) -> i32 {
        fn count_changes(s: &String, mut expected: &str) -> i32 {
            let mut expected = expected.chars().cycle();
            let mut changes = 0;
            for c in s.chars() {
                if Some(c) == expected.next() {
                    changes += 1;
                }
            }
            changes
        }
        min(count_changes(&s, "01"), count_changes(&s, "10"))
    }
}