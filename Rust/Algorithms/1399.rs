use std::collections::HashMap;

impl Solution {
    // Sum digits tradicional way (no conversion to string first.)
    // note: we know n is >= 1.
    fn sum_digits(mut n: i32) -> i32 {
        let mut sum = 0;
        while n > 0 {
            sum += n % 10;
            n /= 10;
        }
        sum
    }

    pub fn count_largest_group(n: i32) -> i32 {
        let sum_digits = Solution::sum_digits;
        let mut counts = HashMap::new();

        // Build counts for each i.
        for i in 1..n + 1 {
            let sd = sum_digits(i);
            match counts.get(&sd) {
                Some(group) => {
                    counts.insert(sd, group + 1);
                }
                None => {
                    counts.insert(sd, 1);
                }
            }
        }
        // Build entries, sort, find counts.
        let mut entries = counts.into_iter().collect::<Vec<(i32, i32)>>();
        entries.sort_unstable_by(|a, b| b.1.partial_cmp(&a.1).unwrap());
        let (mut count, mut group) = (0, 0);
        for (_, value) in entries {
            if group == 0 {
                group = value;
                count = 1;
            } else {
                if group != value {
                    return count;
                }
                count += 1;
            }
        }
        count
    }
}
