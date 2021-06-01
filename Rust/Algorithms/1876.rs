impl Solution {
    pub fn count_good_substrings(s: String) -> i32 {
        let mut count = 0;
        let mut i = 2;
        let end = s.len();
        let chars = s.as_bytes();
        while (i < end) {
            let a = chars[i-2];
            let b = chars[i-1];
            let c = chars[i];
            if (a == b && b == c) {
                i += 2;
                continue;
            }
            count += if a != b && b != c && a != c { 1 } else { 0 };
            i += 1;
        }
        count
    }
}