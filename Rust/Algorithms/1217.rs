impl Solution {
    pub fn min_cost_to_move_chips(position: Vec<i32>) -> i32 {
        let mut odds = 0;
        let len = position.len() as i32;
        for i in position {
            if i % 2 == 1 {
                odds += 1;
            }
        }
        let evens = len - odds;
        match evens > odds {
            true => odds,
            false => evens,
        }
    }
}
