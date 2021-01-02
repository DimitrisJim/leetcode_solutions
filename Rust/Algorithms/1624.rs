use std::collections::HashMap;

impl Solution {
    pub fn max_length_between_equal_characters(s: String) -> i32 {
        let mut d: HashMap<char, Vec<_>> = HashMap::new();
        for (idx, c) in s.chars().enumerate() {
            if (d.contains_key(&c)) {
                let lst = d.get_mut(&c).unwrap();
                if idx > lst[1] {
                    lst[1] = idx;
                }
            } else {
                d.insert(c, vec![idx, idx]);
            }
        }

        let mut max_diff = -1;
        for v in d.values() {
            let (min, max) = (v[0], v[1]);
            if min != max {
                let diff = (max - min - 1) as i32;
                if diff > max_diff {
                    max_diff = diff;
                }
            }
        }
        max_diff
    }
}
