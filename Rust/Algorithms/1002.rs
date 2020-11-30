use std::collections::HashMap;
use std::iter::FromIterator;

impl Solution {
    // Create count of characters in value.
    fn create_counts(value: &str) -> HashMap<char, i32> {
        let mut counter = HashMap::new();
        value.chars().for_each(|c| {
            match counter.get_mut(&c) {
                None => {
                    counter.insert(c, 1);
                }
                Some(count) => *count += 1,
            }
        });
        return counter;
    }

    fn inplace_and(
        common: &mut HashMap<char, i32>,
        other: &HashMap<char, i32>,
    ) {
        // For every key in common, keep the minimum of (common[key], other[key])
        // excluding <= 0 counts.
        common.iter_mut().for_each(|(key, value)| {
            // unwrap_or = Some(x) => x | None => default.
            let othervalue = *other.get(key).unwrap_or(&0);
            if othervalue < *value {
                *value = othervalue;
            }
        });
        // remove all zero's from common, they signify key wasn't present
        // in other.
        common.retain(|_, v| *v != 0);
    }

    // Giant sequance of iterator transformations. Doesn't bail early
    pub fn common_chars(a: Vec<String>) -> Vec<String> {
        a.iter()
            .skip(1)
            // inplace_and => &
            // fold counts(a[0]) & counts(a[1]) & counts(a[2]) ..
            .fold(
                &mut Solution::create_counts(&a[0]),
                |mut acc, value| {
                    Solution::inplace_and(
                        &mut acc,
                        &Solution::create_counts(value),
                    );
                    acc
                },
            )
            // Go through common characters, consuming the map.
            .into_iter()
            // and make Strings out of them.
            .map(|(key, value)| {
                // Need move else key is passed by ref.
                (0..*value).map(move |_| key.to_string())
            })
            .flatten()
            .collect()
    }

    // bails early if commons becomes empty during iteration.
    pub fn common_chars_2(a: Vec<String>) -> Vec<String> {
        let mut commons = Solution::create_counts(&a[0]);
        for value in a.iter().skip(1) {
            Solution::inplace_and(
                &mut commons,
                &Solution::create_counts(value),
            );
            // bail early.
            if commons.len() == 0 {
                return Vec::<String>::new();
            }
        }
        commons
            // Go through common characters, consuming the map.
            .into_iter()
            // and make Strings out of them.
            .map(|(key, value)| {
                // Need move else key is passed by ref.
                (0..value).map(move |_| key.to_string())
            })
            .flatten()
            .collect()
    }
}
