impl Solution {
    pub fn kids_with_candies(candies: Vec<i32>, extra_candies: i32) -> Vec<bool> {
        // deref val returned from max. 
        let max: i32 = *candies.iter().max().expect("This shouldn't happen");
        // map over elements and build result.
        candies.iter().map(|a| (a + extra_candies) >= max).collect()       
    }
}
