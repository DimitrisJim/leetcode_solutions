impl Solution {
    pub fn count_triples(n: i32) -> i32 {
        // precompute all powers from
        let n = n as usize;
        let mut count = 0;
        let mut pows: Vec<_> = (0..n).map(|x| x.pow(2u32) as u16).collect();

        for i in 3..n-1 {
            let si = pows[i];
            for j in i+1..n {
                // c must be integer (perfect square)
                let m = ((si + pows[j]) as f32).sqrt();
                // j only increases, cannot find m > n.
                if m > n as f32{
                    // means m was > n during first iteration,
                    // i.e for consequent iterations it will 
                    // always be > n.
                    if j == i + 1 {
                        return count;
                    }
                    break;
                }
                // m <= n (wasn't aware of this mod trick.)
                if m.round() == m {
                    count += 2;
                }
            }
        }
        count
    }
}