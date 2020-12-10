impl Solution {
    pub fn three_consecutive_odds(arr: Vec<i32>) -> bool {
        let mut count = 0;
        for i in arr {
            count = if i & 1 == 1 { count + 1 } else { 0 };
            if count == 3 {
                return true;
            }
        }
        false
    }
}
