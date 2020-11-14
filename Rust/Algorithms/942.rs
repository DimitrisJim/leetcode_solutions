impl Solution {
    pub fn di_string_match(s: String) -> Vec<i32> {
        let mut res = Vec::with_capacity(s.len() + 1);
        let (mut i, mut j) = (0, s.len() as i32);
        for c in s.chars() {
            match c {
                'I' => {
                    res.push(i);
                    i += 1;
                }
                'D' => {
                    res.push(j);
                    j -= 1;
                }
                _ => (),
            }
        }
        res.push(j);
        res
    }
}
