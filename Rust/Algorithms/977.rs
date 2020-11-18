impl Solution {
    pub fn sorted_squares(mut a: Vec<i32>) -> Vec<i32> {
        for i in a.iter_mut() {
            *i *= *i;
        }
        a.sort_unstable();
        a
    }
}
