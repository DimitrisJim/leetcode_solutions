use std::iter::Map;

impl Solution {
    pub fn maximum_wealth(accounts: Vec<Vec<i32>>) -> i32 {
        accounts
            .into_iter()
            .map(|a| a.into_iter().sum())
            .collect::<Vec<i32>>()
            .into_iter()
            .max()
            .expect("Non Empty Vectors by definition.")
    }
}
