use std::collections::{HashMap, HashSet};

impl Solution {
    pub fn shortest_completing_word(
        license_plate: String,
        mut words: Vec<String>,
    ) -> String {
        let letters: HashSet<_> =
            "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
                .chars()
                .collect();
        let license: Vec<_> = license_plate
            .chars()
            .filter(|x| letters.contains(x))
            .map(|x| x.to_ascii_lowercase())
            .collect();

        // Count characters, keep set of keys.
        let mut ms_license = HashMap::new();
        for c in license.iter() {
            let opt = ms_license.get_mut(&c);
            match opt {
                Some(value) => {
                    *value += 1;
                }
                None => {
                    ms_license.insert(c, 1);
                }
            }
        }
        let s_license: HashSet<_> =
            ms_license.keys().map(|x| **x).collect();

        // sort our vector by the length of the contained strings.
        // note: need stability.
        words.sort_by_key(|x| x.len());
        for w in words {
            let ws: HashSet<_> = w.chars().collect();
            if s_license.is_subset(&ws) {
                // Get a duplicate.
                let mut tmp_counter = ms_license.clone();
                for c in w.chars() {
                    let opt = tmp_counter.get_mut(&c);
                    if let Some(value) = opt {
                        if *value == 1 {
                            tmp_counter.remove(&c);
                        } else {
                            *value -= 1;
                        }
                    }
                }
                if tmp_counter.len() == 0 {
                    return w;
                }
            }
        }
        // Shouldn't reach
        String::from("")
    }
}
