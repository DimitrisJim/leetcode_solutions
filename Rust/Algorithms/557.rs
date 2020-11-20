impl Solution {
    pub fn reverse_words(s: String) -> String {
        // split by " "
        s.split(' ')
            // for every sub-element, reverse and collect
            // into a new string.
            .map(|sub| sub.chars().rev().collect::<String>())
            // collect it all into a vector.
            .collect::<Vec<_>>()
            // and join back on " "
            .join(" ")
    }
}
