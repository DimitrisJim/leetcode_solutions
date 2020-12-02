use std::iter::FromIterator;

impl Solution {
    pub fn shortest_to_char(s: String, c: char) -> Vec<i32> {
        let mut ranges = vec![];
        let mut prev_pos: i32 = -1;
        // Didn't know you could do this :-)
        let (fit, frit) = (Vec::from_iter, Vec::from_iter);
        // Go through indices, don't care about second element.
        for (idx, _) in s.match_indices(c) {
            // First time we bump into c:
            // add increasing distances.
            if prev_pos == -1 {
                ranges.append(&mut frit((0..(idx as i32) + 1).rev()));
            // After first time, we go up and then down.
            } else {
                let diff = idx - (prev_pos as usize);
                let middle = diff as i32 / 2;
                // Diff parity plays a role.
                if diff % 2 == 1 {
                    ranges.append(&mut fit((1..middle + 1)));
                } else {
                    ranges.append(&mut fit((1..middle)));
                }
                ranges.append(&mut frit((0..middle + 1).rev()));
            }
            // Update previous position.
            prev_pos = idx as i32;
        }
        // Add the final distances.
        if (prev_pos as usize) != s.len() - 1 {
            let diff: i32 = s.len() as i32 - prev_pos;
            ranges.append(&mut fit(1..diff));
        }
        ranges
    }
}
