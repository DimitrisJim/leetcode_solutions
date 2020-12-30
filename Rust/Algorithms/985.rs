impl Solution {
    pub fn sum_even_after_queries(
        mut a: Vec<i32>,
        queries: Vec<Vec<i32>>,
    ) -> Vec<i32> {
        let mut evenSum: i32 = a.iter().filter(|x| *x % 2 == 0).sum();
        let mut result = Vec::with_capacity(queries.len());

        for query in queries.into_iter() {
            let (value, index) = (query[0], query[1] as usize);
            let old_value = a[index];
            let new_value = value + old_value;

            // Add new value if its even:
            if new_value % 2 == 0 {
                evenSum += new_value;
            }
            // Subtract old value if it was even.
            if old_value % 2 == 0 {
                evenSum -= old_value;
            }
            a[index] = new_value;
            result.push(evenSum);
        }
        result
    }
}
