impl Solution {
    pub fn str_str(haystack: String, needle: String) -> i32 {
        if (needle.len() == 0) {
            return 0;
        }
        if (needle.len() > haystack.len()) {
            return -1;
        }

        let diff = haystack.len() - needle.len();
        for i in 0..haystack.len() {
            if (i <= diff) {
                if &haystack[i..i + needle.len()] == &needle {
                    return i as i32;
                }
            }
        }
        -1
    }
}
