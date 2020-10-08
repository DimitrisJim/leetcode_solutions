use std::iter::once;

impl Solution {
    pub fn shuffle(nums: Vec<i32>, n: i32) -> Vec<i32> {
        // Rust still seems mystical to me. 
        // Here the main issue are the references; the 
        // rest *should* make intuitive sense.
        //
        // All of this grabbing slices just to call to_vec 
        // in the end though, it seems like we're beating 
        // the point. 
        // I need to come back to this at some point.
        let nx: usize = n as usize;
        let u: &Vec<_> = &nums[..nx].iter()
            .zip(&nums[nx..nums.len()])
            .flat_map(|(a, b)| once(*a).chain(once(*b)))
            .collect();
        u.to_vec()
    }
}
