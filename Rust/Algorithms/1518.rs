impl Solution {
    pub fn num_water_bottles(
        mut num_bottles: i32,
        num_exchange: i32,
    ) -> i32 {
        let mut drinks = num_bottles;
        loop {
            let (d, r) =
                (num_bottles / num_exchange, num_bottles % num_exchange);
            if d == 0 {
                break;
            }
            drinks += d;
            num_bottles = d + r;
        }
        drinks
    }
}
