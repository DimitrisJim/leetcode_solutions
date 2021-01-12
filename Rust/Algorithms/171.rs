impl Solution {
    pub fn title_to_number(s: String) -> i32 {
        let mut length = (s.len() - 1) as u32;
        let mut col = 0;

        for i in s.into_bytes() {
            col += ((i - 64) as i32) * 26i32.pow(length);
            length -= 1;
        }
        col
    }
}
