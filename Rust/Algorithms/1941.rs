impl Solution {
    pub fn are_occurrences_equal(s: String) -> bool {
        let mut freqs = vec![0; 26];
        let chars = s.as_bytes();
        // hold on to first valid char and count frequencies.
        let c = chars[0] - 97;
        for ch in chars {
            freqs[(ch - 97) as usize] += 1;
        }
        // check that all non zero values are equal to target.
        let target = freqs[c as usize];
        for v in freqs.into_iter().filter(|&x| x > 0) {
            if v != target {
                return false;
            }
        }
        true
    }
}
