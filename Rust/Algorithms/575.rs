use std::collections::HashSet;
use std::convert::TryFrom;

impl Solution {
    pub fn distribute_candies(candy_type: Vec<i32>) -> i32 {
        let ammount = candy_type.len() / 2;
        let s: HashSet<_> = candy_type.into_iter().collect();
        if s.len() < ammount {
            i32::try_from(s.len()).unwrap()
        } else {
            i32::try_from(ammount).unwrap()
        }
    }
}
