impl Solution {
    pub fn climb_stairs(n: i32) -> i32 {
        if (n == 1) {
            return 1;
        }
        let mut a = 1u32;
        let mut b = 2u32;
        for _ in 2..n {
            let temp = b;
            b = a + b;
            a = temp;
        }
        b as i32
    }
}
