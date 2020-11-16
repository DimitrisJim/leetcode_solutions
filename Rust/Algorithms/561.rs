impl Solution {
    pub fn array_pair_sum(mut nums: Vec<i32>) -> i32 {
        nums.sort_unstable();
        nums.iter()           // grab iterator
            .rev()            // go from reverse direction
            .skip(1)          // skip the first element
            .step_by(2)       // and step through 2 elements at a time
            .sum()            // and return the sum.
    }
}
