use std::collections::HashSet;

impl Solution {
    pub fn halves_are_alike(s: String) -> bool {
        let vowels: HashSet<_> = "aAiIoOuUeE".chars().collect();
        let mut count = 0;
        let mut s_iter = s.chars();

        // Use s_iter until s.len() / 2.
        for i in 0..s.len() / 2 {
            if vowels.contains(&s_iter.next().unwrap()) {
                count += 1;
            }
        }

        // Exhaust s_iter.
        for i in s.len() / 2..s.len() {
            if vowels.contains(&s_iter.next().unwrap()) {
                count -= 1;
                if count < 0 {
                    return false;
                }
            }
        }
        count == 0
    }
}
