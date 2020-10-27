impl Solution {
    pub fn replace_elements(mut arr: Vec<i32>) -> Vec<i32> {
        let mut max = 0;
        let len = arr.len();
        for i in (0..len).rev() {
            let val = arr[i];
            arr[i] = max;
            if val > max {
                max = val;
            }
        }
        arr[len - 1] = -1;
        arr
    }
}
