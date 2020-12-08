use std::collections::HashSet;
use std::iter::FromIterator;

impl Solution {
    pub fn to_goat_latin(s: String) -> String {
        // Keep vowels around.
        let vowels: HashSet<char> =
            HashSet::from_iter("aAiIeEuUoO".chars());
        let mut result = String::new();

        for (ammount, word) in s.split(" ").enumerate() {
            // Grab iterator for word and the first char
            let mut iter = word.chars();
            let first = iter.next().unwrap();

            // Old switcharoo based on if it's a vowel.
            if vowels.contains(&first) {
                result.push(first);
                result.push_str(&String::from_iter(iter));
            } else {
                result.push_str(&String::from_iter(iter));
                result.push(first);
            }
            // Add the rest.
            result.push_str("ma");
            result.push_str(&"a".repeat(ammount + 1));
            result.push_str(" ");
        }
        // Pop off final erroneous space.
        result.pop();
        result
    }
}
