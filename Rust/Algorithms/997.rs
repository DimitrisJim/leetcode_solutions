impl Solution {
    pub fn find_judge(n: i32, trust: Vec<Vec<i32>>) -> i32 {
        let mut trust_list = vec![0; n as usize];
        for p in trust {
            let (p1, p2) = ((p[0] - 1) as usize, (p[1] - 1) as usize);
            trust_list[p1] = -1;
            if trust_list[p2] >= 0 {
                trust_list[p2] += 1;
            }
        }
        for i in 0..n as usize {
            if (trust_list[i] == n - 1) {
                return (i + 1) as i32;
            }
        }
        -1
    }
}
