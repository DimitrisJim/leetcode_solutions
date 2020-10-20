impl Solution {
    pub fn number_of_steps (mut num: i32) -> i32 {
        let mut count = 0;
        while num != 0 {
            match num & 1 {
                1 => num ^= 1,
                0 => num >>= 1,
                _ => (),
            }
            count += 1;
        }
        count
    }
}
