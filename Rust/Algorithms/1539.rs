impl Solution {
    pub fn find_kth_positive(arr: Vec<i32>, mut k: i32) -> i32 {
        let mut start = 1;
        for j in arr.into_iter() {
            if (start == j) {
                start += 1;
            } else {
                let step = j - start;
                if (step >= k) {
                    return start + k - 1;
                }
                k -= step;
                start = j + 1;
            }
        }
        start + k - 1
    }
}
