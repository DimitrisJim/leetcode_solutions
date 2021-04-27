impl Solution {
    pub fn num_equiv_domino_pairs(dominoes: Vec<Vec<i32>>) -> i32 {
        let mut counts = vec![0; 73];
        let index = |i, j| (9 * (i - 1) - i + j) as usize;
        // Build counts for pairs.
        for pair in dominoes {
            let [a, b] = [pair[0], pair[1]];
            if a > b {
                counts[index(b, a)] += 1;
            } else {
                counts[index(a, b)] += 1;
            }
        }
        // Sum counts.
        let sum = counts.iter().map(|c| (c * (c - 1))).sum::<i32>();
        sum / 2
    }
}
