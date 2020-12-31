impl Solution {
    pub fn find_special_integer(arr: Vec<i32>) -> i32 {
        let threshold = ((arr.len() as f64) * 0.25) as i32;
        let mut count = 0;
        for i in 1..arr.len() {
            if arr[i - 1] == arr[i] {
                count += 1;
                if count > threshold {
                    return arr[i];
                }
            } else {
                count = 1;
            }
        }
        arr[0]
    }
}
