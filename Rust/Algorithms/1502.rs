impl Solution {
    pub fn can_make_arithmetic_progression(mut arr: Vec<i32>) -> bool {
        arr.sort_unstable();
        let step = arr[1] - arr[0];
        for i in 2..arr.len() {
            if arr[i] - arr[i - 1] != step {
                return false;
            }
        }
        true
    }
}
