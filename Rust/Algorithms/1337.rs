impl Solution {
    pub fn k_weakest_rows(mat: Vec<Vec<i32>>, k: i32) -> Vec<i32> {
        let mut inter: Vec<_> = mat
            .iter()
            .map(|x| x.iter().fold(0, |acc, x| acc + x))  // sum rows
            .enumerate()                                  // attach index
            .collect();
        inter.sort_by(|a, b| a.1.cmp(&b.1));              // sort by sum value.
        // and finally return k first.
        inter.iter().take(k as usize).map(|x| x.0 as i32).collect()
    }
}
