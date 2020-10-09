impl Solution {
    pub fn restore_string(s: String, indices: Vec<i32>) -> String {
        // Honestly, found this the trickiest!
        let mut v = Vec::from(s.clone());
        // zip indices with bytes from string and update v.
        for (ind, char) in indices.iter().zip(s.bytes()){
            v[*ind as usize] = char;
        }
        // return string.
        String::from_utf8(v).expect("No failures.")
    }
}
