use std::collections::{HashMap, HashSet};
use std::iter::FromIterator;

impl Solution {
    // Create count of characters in value.
    fn create_counts(value: &str) -> HashMap<char, i32> {
        let mut counter = HashMap::new();
        value.chars().for_each(|c| match counter.get_mut(&c) {
            None => {
                counter.insert(c, 1);
            }
            Some(count) => *count += 1,
        });
        return counter;
    }

    fn can_build(
        me: &HashMap<char, i32>,
        other: &HashMap<char, i32>,
    ) -> bool {
        // Go through each k pair in me and count how
        // many values are <= than other[k].
        let mut count = 0;
        me.iter().for_each(|(key, value)| {
            // unwrap_or = Some(x) => x | None => default.
            let othervalue = *other.get(key).unwrap_or(&0);
            if othervalue >= *value {
                count += 1;
            }
        });
        // Needs to be true in order to be able to build
        // me from other.
        me.len() == count
    }

    pub fn count_characters(words: Vec<String>, chars: String) -> i32 {
        let create_counts = Solution::create_counts;
        let can_build = Solution::can_build;

        // Initialize structures/values needed.
        let cset: HashSet<char> = HashSet::from_iter(chars.chars());
        let ccount = create_counts(&chars);
        let clen = chars.len();

        words
            .iter()
            // First filter by length. Longer strings *can't* be built.
            .filter(|w| w.len() < clen)
            // Filter by membership in the chars set.
            .filter(|w| w.chars().all(|c| cset.contains(&c)))
            // Finally, filter by the ones we can actually build.
            .filter(|w| can_build(&create_counts(w), &ccount))
            // And return their length.
            .map(|w| w.len())
            .sum::<usize>() as i32
    }
}
