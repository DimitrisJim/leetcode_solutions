impl Solution {
    pub fn average(mut salary: Vec<i32>) -> f64 {
        let div = f64::from((salary.len() - 2) as i32);
        salary.sort_unstable();
        let sum = *&salary[1..salary.len() - 1].iter().fold(0, |acc, x| acc + x);
        f64::from(sum) / div
    }
}
