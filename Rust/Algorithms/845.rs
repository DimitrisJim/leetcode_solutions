use std::cmp::max;

impl Solution {
    pub fn longest_mountain(arr: Vec<i32>) -> i32 {
        let mut i = 0;
        let mut max_ = 0;
        let end = arr.len() - 1;
        while i < end {
            let mut up = 1;
            let mut k = i;
            while k < end && arr[k] < arr[k + 1] {
                up += 1;
                k += 1;
            }
            // Start looking for a way down if we've found a
            // way up.
            if up > 1 {
                let mut down = 0;
                while k < end && arr[k] > arr[k + 1] {
                    down += 1;
                    k += 1;
                }
                // must have both down and up to have a mountain.
                if down > 0 {
                    max_ = max(max_, up + down);
                    i += down - 1;
                }
            }
            // start looking again after the peak (if none were found
            // this will be == 1)
            i += up;
        }
        max_ as i32
    }
}
