use std::collections::HashSet;


impl Solution {
    pub fn reverse_vowels(mut s: String) -> String {
        let vowels: HashSet<u8> = vec![97u8, 101, 105, 111, 117, 65, 69, 73, 79, 85].into_iter().collect();
        
        // Safety guarantees are respected since we only pass contents that are already in the string.
        // We know they will be valid UTF-8.
        unsafe {
            let bytes = s.as_mut_vec();
            let mut start = 0;
            let mut end = bytes.len() - 1;
            while end > start {
                while end > start && !vowels.contains(&bytes[end]) {
                    end -= 1;
                }
                while end > start && !vowels.contains(&bytes[start]) {
                    start += 1;
                }
                let tmp = bytes[end];
                bytes[end] = bytes[start];
                bytes[start] = tmp;
                if end == 0 {
                    break;
                }
                end -= 1;
                start += 1;
            }
        }
        s
    }
}