impl Solution {
    pub fn make_good(s: String) -> String {
        let mut res = Vec::new();
        // Go through s using byte values, we know input
        // is lowercase eng chars.
        let sv = s.as_bytes();
        let (end, mut i) = (sv.len() - 1, 0);

        while i < end {
            // If diff == 32, we have a bad pair, skip over it.
            let diff = (sv[i] as i32 - sv[i + 1] as i32).abs();
            if (diff == 32) {
                i += 2;
                // Now that we have skipped over it, we need to
                // check for the case that a character added to res
                // previously, makes a bad pair with the new char in
                // sv.
                while (i <= end && res.len() > 0) {
                    // last returns ref to last element.
                    let diff =
                        (sv[i] as i32 - *res.last().unwrap() as i32).abs();
                    if diff == 32 {
                        res.pop();
                        i += 1;
                    } else {
                        break;
                    }
                }
            // If not part of a bad pair, add to res.
            } else {
                res.push(sv[i]);
                i += 1;
            }
        }
        // If final while iteration hits the else, we need to add
        // final char not touched.
        if i == end {
            res.push(sv[i]);
        }
        String::from_utf8(res).unwrap()
    }
}
