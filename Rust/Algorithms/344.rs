impl Solution {
    pub fn reverse_string(s: &mut Vec<char>) {
        if s.len() == 0 {
            return;
        }
        let (mut i, mut j) = (0, s.len() - 1);
        while (i < j) {
            let temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i += 1;
            j -= 1;
        }
    }
}
