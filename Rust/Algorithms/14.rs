use std::cmp::min;

impl Solution {
    pub fn longest_common_prefix(strs: Vec<String>) -> String {
        // We know we have at least 1 element.
        let mut it = strs.iter().map(|s| s.as_bytes());
        let mut prefix = it.next().unwrap();

        for s in it {
            let (mut i, end) = (0, min(prefix.len(), s.len()));

            while i < end && s[i] == prefix[i] {
                i += 1;
            }
            if i == 0 {
                return String::new();
            }
            prefix = &prefix[..i];
        }
        String::from_utf8(prefix.to_vec()).unwrap()
    }
}
