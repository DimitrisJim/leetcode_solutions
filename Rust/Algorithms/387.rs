impl Solution {
    pub fn first_uniq_char(s: String) -> i32 {
        let mut chars = vec![0; 26];
        let cpoints = s.as_bytes();

        for p in cpoints {
            chars[(p - 97) as usize] += 1;
        }

        let mut idx = 0;
        for p in cpoints {
            if chars[(p - 97) as usize] == 1 {
                return idx;
            }
            idx += 1
        }
        -1
    }
}
