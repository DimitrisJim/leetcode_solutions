impl Solution {
    pub fn process_queries(queries: Vec<i32>, m: i32) -> Vec<i32> {
        let mut P: Vec<_> = (1..m + 1).collect();
        let mut res = vec![];

        for i in queries {
            let mut v = P.iter().position(|&r| r == i).unwrap() as i32;
            res.push(v);
            v = P.remove(v as usize);
            P.insert(0, v);
        }
        res
    }
}
