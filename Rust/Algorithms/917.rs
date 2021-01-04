use std::collections::HashSet;

impl Solution {
    pub fn reverse_only_letters(s: String) -> String {
        if s.len() == 0 {
            return s;
        }
        let letters: HashSet<_> =
            "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
                .chars()
                .collect();
        let (mut start, mut end) = (0, s.len() - 1);
        let mut S: Vec<_> = s.chars().collect();

        while start < end {
            while !letters.contains(&S[start]) {
                if start == end {
                    return S.iter().collect::<String>();
                }
                start += 1;
            }
            while !letters.contains(&S[end]) {
                if start == end {
                    return S.iter().collect::<String>();
                }
                end -= 1;
            }
            let tmp = S[start];
            S[start] = S[end];
            S[end] = tmp;
            start += 1;
            end -= 1;
        }
        S.iter().collect::<String>()
    }
}
