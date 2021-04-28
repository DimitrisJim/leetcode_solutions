use std::collections::HashMap;

impl Solution {
    pub fn frequency_sort(s: String) -> String {
        let mut counter = HashMap::new();

        for c in s.chars() {
            let count = counter.entry(c).or_insert(0usize);
            *count += 1;
        }

        let mut sorted_pairs =
            counter.into_iter().collect::<Vec<(_, _)>>();
        sorted_pairs.sort_unstable_by_key(|k| k.1);

        let mut result = String::from("");
        for (c, count) in sorted_pairs.into_iter().rev() {
            result.push_str(&c.to_string().repeat(count));
        }
        result
    }
}
