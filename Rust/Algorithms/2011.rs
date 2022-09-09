impl Solution {
    pub fn final_value_after_operations(operations: Vec<String>) -> i32 {
        // loop would probably be better?
        operations.iter().map(|op| op.contains('+').then(|| 1).unwrap_or(-1)).sum()
    }
}