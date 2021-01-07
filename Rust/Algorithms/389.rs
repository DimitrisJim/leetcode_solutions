impl Solution {
    pub fn find_the_difference(s: String, t: String) -> char {
        let mut x: u8 = 0;
        // Go through chars as u8 array and xor'em.
        for i in s.as_bytes().iter().chain(t.as_bytes().iter()) {
            x ^= i;
        }
        char::from(x)
    }
}
