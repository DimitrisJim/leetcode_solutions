impl Solution {
    pub fn are_numbers_ascending(s: String) -> bool {
        let (mut previous, mut next) = (0, 0);
        let mut it = s.chars();
        loop {
            let mut c = match it.next() {
                None => break,
                Some(c) => c,
            };
            let mut digit = 0;
            loop {
                if c.is_digit(10) {
                    digit *= 10;
                    digit += c.to_digit(10).unwrap();
                    c = match it.next() {
                        None => break,
                        Some(c) => c,
                    };
                } else {
                    break;
                }
            }
            if digit > 0 {
                next = digit;
                if next <= previous {
                    return false;
                }
                previous = next;
            }
        }
        return true;
    }
}