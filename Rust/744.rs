impl Solution {
    pub fn next_greatest_letter(letters: Vec<char>, target: char) -> char {
        if target >= letters[letters.len() - 1] {
            return letters[0];
        }

        letters.into_iter().find(|&x| x > target).unwrap()
    }
}
