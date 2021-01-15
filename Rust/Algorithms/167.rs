impl Solution {
    pub fn two_sum(numbers: Vec<i32>, target: i32) -> Vec<i32> {
        let (mut i, mut j) = (0, numbers.len() - 1);
        // Note: *Can* use loop since we know a solution exists,
        // in general, better to break and return.
        loop {
            let ts = numbers[i] + numbers[j];
            if ts == target || i > j {
                break vec![(i + 1) as i32, (j + 1) as i32];
            }
            if ts > target {
                j -= 1;
            } else {
                i += 1;
            }
        }
    }
}
