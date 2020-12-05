impl Solution {
    pub fn minimum_abs_difference(mut arr: Vec<i32>) -> Vec<Vec<i32>> {
        let mut result = vec![];
        let mut min_diff = i32::max_value();
        arr.sort_unstable();
        for k in 0..arr.len() - 1 {
            let diff = (arr[k + 1] - arr[k]).abs();
            if diff < min_diff {
                min_diff = diff;
                result = vec![vec![arr[k], arr[k + 1]]];
            } else if diff == min_diff {
                result.push(vec![arr[k], arr[k + 1]]);
            }
        }
        result
    }
}
