impl Solution {
    pub fn min_bit_flips(start: i32, goal: i32) -> i32 {
        let mut count = 0;
        let (mut b, mut s) = if start > goal { (start, goal) } else { (goal, start) };
    
        while s > 0 {
            if b & 1 != s & 1 {
                count += 1;
            }
            b >>= 1;
            s >>= 1;
        }
        
        while b > 0 {
            if b & 1 == 1 {
                count += 1;
            }
            b >>= 1;
        }
        count
    }
}