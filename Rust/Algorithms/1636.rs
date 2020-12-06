use std::collections::HashMap;

impl Solution {
    pub fn frequency_sort(nums: Vec<i32>) -> Vec<i32> {
        let mut freqs: HashMap<i32, i32> = HashMap::new();
        for i in nums {
            // Build frequencies.
            match freqs.get_mut(&i) {
                Some(freq) => *freq += 1,
                None => {
                    freqs.insert(i, 1);
                }
            }
        }
        // Collect into a vector then:
        //   - Unstable sort by the value.
        //   - Stable sort by frequency.
        let mut vfreqs: Vec<(i32, i32)> = freqs.into_iter().collect();
        vfreqs.sort_unstable_by_key(|k| k.0);
        // Sort but reversed.
        vfreqs.sort_by(|a, b| b.1.partial_cmp(&a.1).unwrap());
        // Go through and build resulting vector.
        let mut result = Vec::new();
        for (v, f) in vfreqs.into_iter().rev() {
            result.resize(result.len() + f as usize, v);
        }
        result
    }
}
