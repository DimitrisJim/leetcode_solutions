impl Solution {
    pub fn most_visited(n: i32, rounds: Vec<i32>) -> Vec<i32> {
        let length = rounds.len();
        let mut begin = [0, 0];

        // Check if we start from sector 1 or if we start
        // from some odd position. If so, keep track of where
        // we start (since these will contribute +1 to their)
        // visited count.
        let mut i = 0;
        if rounds[i] != 1 {
            let start = rounds[0];
            // find out if we perform a cycle around track.
            while (i < length - 1) && rounds[i] < rounds[i + 1] {
                i += 1;
            }
            // didn't cycle through track, return
            if i == length - 1 {
                let mut result = vec![];
                for i in start..rounds[length - 1] + 1 {
                    result.push(i);
                }
                return result;
            }
            // Else, keep around initial sectors ran.
            begin[0] = start;
            begin[1] = n;
        }
        // The final sectors ran (anything between will essentially be
        // a cycle so +1 for everything.)
        let mut res = vec![0; n as usize];
        let trail = if rounds[length] - 1 == n {
            [0, 0]
        } else {
            [1, rounds[length - 1]]
        };
        for pair in &[begin, trail] {
            let (s, e) = (pair[0], pair[1]);
            if (s != 0) {
                for i in s..=e {
                    res[(i - 1) as usize] += 1;
                }
            }
        }

        // Find max and return elements with value == max.
        let m = res.iter().max().unwrap();
        let mut r = vec![];
        for (idx, v) in res.iter().enumerate() {
            if v == m {
                r.push((idx + 1) as i32);
            }
        }
        return r;
    }
}
