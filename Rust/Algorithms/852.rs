impl Solution {
    pub fn peak_index_in_mountain_array(arr: Vec<i32>) -> i32 {
        let (mut i, mut j) = (0 as usize, arr.len());
        let mut m: usize = (i + j) / 2;
        loop {
            let mid = arr[m];
            if arr[m + 1] > mid {
                i = m + 1;
            } else if arr[m - 1] > mid {
                j = m - 1;
            } else {
                break;
            }
            m = (i + j) / 2;
        }
        m as i32
    }
}
