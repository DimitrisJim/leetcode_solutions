impl Solution {
    pub fn get_maximum_generated(n: i32) -> i32 {
        if (n < 2) {
            return n;
        }

        let mut A = vec![0; (n + 1) as usize];
        let mut max = 0;
        A[1] = 1;
        for i in 2..=(n as usize) {
            let (q, r) = (i / 2, i % 2);
            let val = A[q];
            if (val > max) {
                max = val;
            }
            A[i] = if (r == 1) {
                let add = val + A[q + 1];
                if (add > max) {
                    max = add;
                }
                add
            } else {
                val
            }
        }
        max
    }
}
