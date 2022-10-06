impl Solution {
    pub fn is_same_after_reversals(num: i32) -> bool {
        if num == 0 { true } else { num % 10 != 0 }
    }
}