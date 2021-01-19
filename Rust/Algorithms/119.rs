impl Solution {
    pub fn get_row(n: i32) -> Vec<i32> {
        let mut res = vec![1];
        let (mid, odd) = if (n + 1) & 1 == 0 {
            ((n + 1) / 2, false)
        } else {
            ((n + 1) / 2 + 1, true)
        };
        for k in 1..mid {
            let prev = res[(k - 1) as usize] as f64;
            res.push(
                (prev * ((n + 1 - k) as f64 / k as f64)).round() as i32
            );
        }
        if odd {
            res.append(
                &mut res.clone().into_iter().rev().skip(1).collect(),
            );
        } else {
            res.append(&mut res.clone().into_iter().rev().collect());
        }
        res
    }
}
