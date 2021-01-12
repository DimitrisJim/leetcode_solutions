impl Solution {
    pub fn total_money(n: i32) -> i32 {
        let (weeks, days) = (n / 7, n % 7);
        let (mut week_sum, mut partial) = (28, 0);

        for i in 0..weeks {
            partial += week_sum;
            week_sum += 7;
        }
        for i in 1..days + 1 {
            partial += weeks + i;
        }
        partial
    }
}
