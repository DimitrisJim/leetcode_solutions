impl Solution {
    pub fn is_perfect_square(x: i32) -> bool {
        if x == 1 {
            return true;
        }
        // Rough initial estimate can only be >= x.
        // Use Babylonian (?) method. Next guess is
        // arithmetic mean of [g, x/g].
        let x: i64 = x.into();
        let mut guess = (x >> 1);
        while guess * guess > x {
            guess = (guess + x / guess) >> 1;
        }
        guess * guess == x
    }
}
