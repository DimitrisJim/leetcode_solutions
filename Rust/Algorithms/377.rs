impl Solution {
    pub fn combination_sum4(nums: Vec<i32>, target: i32) -> i32 {
        let len = (target + 1) as usize;
        let mut a: Vec<u32> = vec![0; len];
        let nums: Vec<_> = nums.into_iter().map(|x| x as usize).collect();
        a[0] = 1;
        for i in 0..len {
            if (a[i] == 0) {
                continue;
            }
            for v in nums.iter() {
                let p = v + i;
                if p < len {
                    a[p] += a[i];
                }
            }
        }
        a[len - 1] as i32
    }
}
