// See:
// https://en.wikipedia.org/wiki/Pascal%27s_triangle#Calculating_a_row_or_diagonal_by_itself
impl Solution {
    pub fn generate(num_rows: i32) -> Vec<Vec<i32>> {
        let mut result = Vec::with_capacity(num_rows as usize);
        for n in 0..num_rows {
            let mut inner = vec![1];
            let (mid, odd) = if (n + 1) & 1 == 0 {
                ((n + 1) / 2, false)
            } else {
                ((n + 1) / 2 + 1, true)
            };
            for k in 1..mid {
                let prev = *inner.last().unwrap() as f64;
                inner.push(
                    (prev * ((n + 1 - k) as f64 / k as f64)).round()
                        as i32,
                );
            }
            if odd {
                inner.append(
                    &mut inner.clone().into_iter().rev().skip(1).collect(),
                );
            } else {
                inner.append(
                    &mut inner.clone().into_iter().rev().collect(),
                );
            }
            result.push(inner);
        }
        result
    }
}
