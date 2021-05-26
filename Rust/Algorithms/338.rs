impl Solution {
    pub fn count_bits(n: i32) -> Vec<i32> {
        let n = n as usize;
        let mut res = vec![0; n + 1];
        for i in 1..n + 1 {
            // i >> 1 will always be smaller than `i` and
            // present in the array.
            // i & 1 checks if we shifted off a zero or a one
            // (and, respectively adds 0 or 1 to the result)
            res[i] = res[i >> 1] + if (i & 1 == 1) { 1 } else { 0 };
        }
        res
    }
}
