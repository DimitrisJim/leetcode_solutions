impl Solution {
    pub fn cells_in_range(s: String) -> Vec<String> {
        let bts = s.as_bytes();
        let (c1, r1, c2, r2) = (bts[0], bts[1], bts[3], bts[4]);
        let mut res = vec![];
        
        for i in c1..=c2 {
            for j in r1..=r2 {
                // not sure if this is the best way
                let (c, r) = (i as char, j as char);
                res.push(format!("{c}{r}"))
            }
        }

        res
    }
}