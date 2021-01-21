impl Solution {
    pub fn can_construct(ransom_note: String, magazine: String) -> bool {
        let mut letters = vec![0; 26];

        for i in magazine.as_bytes() {
            letters[(i - 97) as usize] += 1;
        }
        for i in ransom_note.as_bytes() {
            let idx = (i - 97) as usize;
            if letters[idx] == 0 {
                return false;
            }
            letters[idx] -= 1;
        }
        true
    }
}
