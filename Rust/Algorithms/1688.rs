impl Solution {
    pub fn number_of_matches(mut n: i32) -> i32 {
        let (mut c, mut r) = (0, 0);
        while n > 1 {
            r = n % 2;
            n = n / 2;
            c += n + r;
        }
        c
    }
}
