impl Solution {
    pub fn max_score(s: String) -> i32 {
        let mut max = (s.matches('1').count() as i32)
            + if s.starts_with("1") { -1 } else { 1 };

        let mut tmp = max;
        let mut it = s.chars().skip(1).peekable();
        loop {
            let next = it.next();
            // peek before altering tmp
            if it.peek().is_none() {
                break;
            }
            tmp += match next {
                Some('0') => 1,
                // We never reach None case.
                _ => -1,
            };
            if (tmp > max) {
                max = tmp;
            }
        }
        max
    }
}
