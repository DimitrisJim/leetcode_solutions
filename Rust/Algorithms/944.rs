use std::collections::HashSet;

impl Solution {
    pub fn min_deletion_size(a: Vec<String>) -> i32 {
        let rlen = a[0].len();
        let mut indices: HashSet<_> = (0..rlen).collect();

        // Basically like fold_first, use the first value as
        // initial value for acc.
        a.iter().skip(1).fold(a[0].clone(), |acc, cur| {
            // Can't index otherwise. Still, maybe iterate
            // through the pairs is better?
            let acc_v: Vec<_> = acc.chars().collect();
            let cur_v: Vec<_> = cur.chars().collect();
            for idx in indices.clone() {
                if cur_v[idx] < acc_v[idx] {
                    indices.remove(&idx);
                }
            }
            cur.to_owned()
        });
        (rlen - indices.len()) as i32
    }
}
