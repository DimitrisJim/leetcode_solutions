use std::collections::HashMap;

impl Solution {
    // Calculate frequency of smallest character.
    fn frequency(s: &String) -> i32 {
        let mut count = 1;
        let mut v: Vec<_> = s.chars().collect();

        v.sort_unstable();
        for i in 1..v.len() {
            if v[i - 1] != v[i] {
                return count;
            }
            count += 1;
        }
        count
    }

    pub fn num_smaller_by_frequency(
        queries: Vec<String>,
        words: Vec<String>,
    ) -> Vec<i32> {
        let frequency = Solution::frequency;
        let mut word_frequencies: Vec<_> =
            words.iter().map(frequency).collect();
        let (mut result, mut cache) =
            (Vec::with_capacity(queries.len()), HashMap::new());
        let wlen = words.len();

        // Word frequencies must be sorted:
        word_frequencies.sort_unstable();
        for q in queries.iter() {
            let freq = frequency(q);

            if !cache.contains_key(&freq) {
                for i in 0..wlen {
                    if freq < word_frequencies[i] {
                        cache.insert(freq, wlen - i);
                        break;
                    }
                }
                // No word frequency is smaller => 0
                if !cache.contains_key(&freq) {
                    cache.insert(freq, 0);
                }
            }
            result.push(*cache.get(&freq).unwrap() as i32);
        }
        result
    }
}
