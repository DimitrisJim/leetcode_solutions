use std::collections::HashMap;

impl Solution {
    pub fn judge_circle(moves: String) -> bool {
        // Use a bunch of counters.
        let (mut u, mut d, mut l, mut r) = (0, 0, 0, 0);
        for i in moves.chars() {
            // and match the character.
            match i {
                'L' => l += 1,
                'R' => r += 1,
                'U' => u += 1,
                'D' => d += 1,
                _ => (),
            }
        }
        // return true if they are equal.
        (l == r) && (u == d)
    }
}
