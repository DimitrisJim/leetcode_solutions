impl Solution {
    pub fn generate_the_string(n: i32) -> String {
        if n == 1 {
            return String::from("a");
        }
        let (excess, takes) = match n & 1 == 1 {
            true => ("bc", n-2),
            false => ("b", n-1),
        };
        let mut res: String = "a"
            .chars()
            .into_iter()
            .cycle()
            .take(takes as usize)
            .collect();
        res.push_str(excess);
        res
    }
}
