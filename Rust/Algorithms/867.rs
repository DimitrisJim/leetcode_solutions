impl Solution {
    pub fn transpose(a: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let (rows, columns) = (a.len(), a[0].len());
        let mut result = Vec::with_capacity(columns);

        for i in 0..columns {
            let mut sub = Vec::with_capacity(rows);
            for j in 0..rows {
                sub.push(a[j][i]);
            }
            result.push(sub);
        }
        result
    }
}
