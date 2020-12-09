impl Solution {
    pub fn trim_mean(mut arr: Vec<i32>) -> f64 {
        let length = arr.len();
        let trim = ((length as f32) * 0.05) as usize;
        arr.sort_unstable();
        // Sum and divide.
        ((*&arr[trim..length - trim].iter().sum::<i32>()) as f64)
            / (length - 2 * trim) as f64
    }
}
