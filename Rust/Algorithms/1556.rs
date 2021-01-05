impl Solution {
    pub fn thousand_separator(u: i32) -> String {
        let mut res = vec![];
        let n = u.to_string();
        let (length, mut count) = (n.len(), 0);

        for i in n.chars().rev() {
            if (count == 3) {
                res.push('.');
                count = 1;
            } else {
                count += 1;
            }
            res.push(i);
        }
        res.into_iter().rev().collect()
    }
}
