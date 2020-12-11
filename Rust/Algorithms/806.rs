use std::collections::HashMap;

impl Solution {
    pub fn number_of_lines(widths: Vec<i32>, s: String) -> Vec<i32> {
        let cwidths = String::from("abcdefghijklmnopqrstuvwxyz")
            .chars()
            .zip(widths.into_iter())
            .collect::<HashMap<_, _>>();

        let (mut lines, mut line) = (0, 0);
        for c in s.chars() {
            // Guaranteed to be lowercase eng letters.
            let width = *cwidths.get(&c).unwrap();
            line += width;
            if line > 100 {
                lines += 1;
                line = width;
            }
        }
        vec![lines + if line > 0 { 1 } else { 0 }, line]
    }
}
