use rand::prelude::*;

struct Solution {
    nums: Vec<i32>,
    rng: ThreadRng,
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl Solution {

    fn new(nums: Vec<i32>) -> Self {
        Self { nums, rng: thread_rng() }
    }
    
    /** Resets the array to its original configuration and return it. */
    fn reset(&self) -> Vec<i32> {
        self.nums.clone()
    }
    
    /** Returns a random shuffling of the array. */
    fn shuffle(&mut self) -> Vec<i32> {
        let mut result: Vec<i32> = self.nums.clone();
        
        for i in 0..result.len()-1 {
            let idx = self.rng.gen_range(i, result.len());
            let tmp = result[i];
            result[i] = result[idx];
            result[idx] = tmp;
        }
        result
    }
}