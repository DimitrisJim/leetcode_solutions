impl Solution {
    pub fn contains_nearby_almost_duplicate(nums: Vec<i32>, k: i32, t: i32) -> bool {
        let mut u: Vec<_> = nums
            .into_iter()
            .enumerate()
            .map(|(i, v)| (i as i32, v as i64))
            .collect();
        u.sort_unstable_by_key(|&(i, v)| v);
        let t = t as i64; 

        for i in 0..u.len() {
            let mut j = i + 1;
            while j < u.len() && u[j].1 - u[i].1 <= t as i64 {
                if (u[i].0 - u[j].0).abs() <= k {
                    return true;
                }
                j += 1;
            }
        }
        false
    }
}