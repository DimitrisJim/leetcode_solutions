impl Solution {
    pub fn sort_array_by_parity_ii(a: Vec<i32>) -> Vec<i32> {
        let mut res = vec![0; a.len()];
        let [mut oddp, mut evenp] = [1, 0];
        for i in a {
            if i % 2 == 1 {
                res[oddp] = i;
                oddp += 2;
            } else {
                res[evenp] = i;
                evenp += 2;
            }
        }
        res
    }
}
