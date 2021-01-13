use std::collections::{HashMap, HashSet};

impl Solution {
    pub fn roman_to_int(s: String) -> i32 {
        let special: HashSet<_> = ["IV", "IX", "XL", "XC", "CD", "CM"]
            .iter()
            .cloned()
            .collect();
        let rtoi: HashMap<_, _> = [
            ("I", 1),
            ("V", 5),
            ("X", 10),
            ("L", 50),
            ("C", 100),
            ("D", 500),
            ("M", 1000),
        ]
        .iter()
        .cloned()
        .collect();

        let (mut i, mut n, end) = (0, 0, s.len() - 1);
        while i < end {
            let ch = &s[i..i + 1];
            if special.contains(&s[i..i + 2]) {
                n = n - rtoi.get(ch).unwrap()
                    + rtoi.get(&s[i + 1..i + 2]).unwrap();
                i += 2;
                continue;
            }
            n += rtoi.get(ch).unwrap();
            i += 1;
        }
        if i == (end + 1) {
            n
        } else {
            n + rtoi.get(&s[end..end + 1]).unwrap()
        }
    }
}
