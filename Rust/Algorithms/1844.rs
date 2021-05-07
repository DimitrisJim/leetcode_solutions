impl Solution {
    pub fn replace_digits(mut s: String) -> String {
        unsafe {
            // SAFETY: Due to input condition as stated:
            //
            //             - shift(s[i-1], s[i]) <= 'z' for all odd indices i
            //
            //         We only create valid u8 values by adding a value between
            //         [0-9] (v[i] - 48 where v[i] in '12..9') to the preceding character
            //         which, by the condition, will not result in a char > 'z'.
            let mut v = s.as_mut_vec();
            let mut i = 1;
            while i < v.len() {
                v[i] = v[i - 1] + (v[i] - 48);
                i += 2;
            }
        }
        s
    }
}
