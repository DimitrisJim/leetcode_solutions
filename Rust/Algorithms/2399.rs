impl Solution {
    pub fn check_distances(s: String, mut distance: Vec<i32>) -> bool {
        let mut s = s.as_bytes();
        for (i, ch) in s.iter().enumerate() {
            let pos = (ch - 97) as usize;

            let dist = distance[pos] + 1;
            if dist == -1 {
                continue;
            } else {
                distance[pos] = -2;
            }
            let dist = (dist as usize) + i;
            if dist < s.len() && s[dist] == s[i] {
                continue;
            } else {
                return false;
            }
        }
        true
    }
}
