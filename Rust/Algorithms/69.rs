impl Solution {
    pub fn my_sqrt(x: i32) -> i32 {
        if x == 1 {
            return 1;
        }
        // Rough initial estimate can only be >= x.
        // Use Babylonian (?) method. Next guess is
        // arithmetic mean of [g, x/g].
        let x: i64 = x.into();
        let mut guess = (x >> 1);
        while guess * guess > x {
            guess = (guess + x / guess) >> 1;
        }
        // should never be > than i32.
        guess as i32
    }
}
