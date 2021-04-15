impl Solution {
    pub fn find_max_average(nums: Vec<i32>, k: i32) -> f64 {
        // Get lim and transform k and nums into f64's for convenience.
        let lim: usize = (k - 1) as usize;
        let k = k as f64;
        let nums: Vec<_> = nums.iter().map(|&x| x as f64).collect();
        let mut max_avg = -1.7976931348623157e+10_f64;
        
        // Build partial average and go through value searching for max.
        let mut partial_avg = nums[0..lim].iter().sum::<f64>() / k;
        for i in lim..nums.len() {
            let last = nums[i] / k;
            let candidate = partial_avg + last;
            if candidate > max_avg {
                max_avg = candidate;
            }
            partial_avg += (last - nums[i - lim] / k);
        }
        max_avg
    }
}