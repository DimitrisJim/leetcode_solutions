impl Solution {
    pub fn fib(mut n: i32) -> i32 {
        let (mut f, mut fprev) = (1, 0);
        while (n > 0) {
            let temp = f;
            f = temp + fprev;
            fprev = temp;
            n -= 1;
        }
        fprev
    }
}
