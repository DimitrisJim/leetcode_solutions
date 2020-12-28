impl Solution {
    pub fn max_power(s: String) -> i32 {
        // Need to start from 1 to handle case where
        // all chars are distinct.
        let (mut max_substr, mut count) = (1, 0);
        // Use char not in s.
        let mut current = ' ';
        s.chars().for_each(|c| {
            if c == current {
                count += 1;
                if count > max_substr {
                    max_substr = count;
                }
            } else {
                count = 1;
                current = c;
            }
        });
        max_substr
    }
}
