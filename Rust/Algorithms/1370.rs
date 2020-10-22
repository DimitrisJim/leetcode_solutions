use std::collections::{HashSet, HashMap};
use std::iter::FromIterator;

impl Solution {
    pub fn sort_string(s: String) -> String {
        let h: HashSet<_> = s.chars().collect();
        let mut sl: Vec<_> = h.iter().cloned().collect();
        sl.sort();
        let revsl: Vec<_> = sl.iter().cloned().rev().collect();
        
        // Bail early
        if sl.len() == 1 {
            return s;
        }
        
        // Count characters in s
        let mut counts = HashMap::new();
        for ch in s.chars() {
            let counter = counts.entry(ch).or_insert(0);
            *counter += 1;
        }

        let mut result = Vec::new();
        let (mut toggle, mut pending) = (false, true);
        // Go forwards + backwards in sl/revsl and build 
        // result by decreasing count values in counts.
        while pending {
            // toggle direction
            let it = match toggle {
                false => &sl,
                true => &revsl,
            };
            for i in it {
                if counts.contains_key(i) {
                    match counts.get(i).expect("The unexpected") {
                        // Remove it. If len == 1, break.
                        1 => {
                            counts.remove(i);
                            if counts.len() == 1 {
                                pending = !pending;
                            }
                        },
                        // Decrease value and continue
                        _ => {
                            *counts.get_mut(i).unwrap() -= 1;
                        }
                    }
                    result.push(*i);
                }
            }
            toggle = !toggle;
        }
        // Add remaining values, if they exist.
        if counts.len() == 1 {
            let (key, val) = counts.iter().nth(0).expect("The unexpected");
            for _ in 0..*val {
                result.push(*key);
            }
        }
        String::from_iter(result)
    }
}
