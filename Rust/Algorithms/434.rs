impl Solution {
    pub fn count_segments(s: String) -> i32 {
        s.split(' ').filter(|x| x.len() > 0).count() as i32
    }
}
