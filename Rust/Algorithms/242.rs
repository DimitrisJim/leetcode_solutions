use std::collections::HashMap;

impl Solution {
    pub fn is_anagram(s: String, t: String) -> bool {
        if s.len() != t.len() {
            return false;
        }
        // Build hashmap from one string
        let mut hs = HashMap::new();
        for c in s.chars() {
            let opt = hs.get_mut(&c);
            match opt {
                Some(v) => {
                    *v += 1;
                }
                None => {
                    hs.insert(c, 1);
                }
            }
        }
        // reduce it from the other one.
        for chr in t.chars() {
            let opt = hs.get_mut(&chr);
            match opt {
                Some(v) => {
                    *v -= 1;
                    if *v == 0 {
                        hs.remove(&chr);
                    }
                }
                None => {
                    return false;
                }
            }
        }
        true
    }
}
