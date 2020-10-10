impl Solution {
    pub fn subtract_product_and_sum(n: i32) -> i32 {
        let (mut p, mut s, mut mn) = (1, 0, n);
        // divmod mn and add/multiply values.
        while (mn != 0) {
            let d = mn.rem_euclid(10);
            s += d;
            p *= d;
            mn /= 10;
        }
        p - s
    }
}
