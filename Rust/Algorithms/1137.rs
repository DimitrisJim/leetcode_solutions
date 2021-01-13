impl Solution {
    pub fn tribonacci(n: i32) -> i32 {
        let (mut a, mut b, mut c) = (0, 1, 1);
        for i in 0..n - 2 {
            let (tmp_a, tmp_b) = (a, b);
            a = b;
            b = c;
            c = tmp_a + tmp_b + c;
        }

        // take care of n == 0 case.
        if n == 0 {
            0
        } else {
            c
        }
    }
}
