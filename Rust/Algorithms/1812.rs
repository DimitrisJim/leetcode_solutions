impl Solution {
    pub fn square_is_white(mut coordinates: String) -> bool {
        // See: https://stackoverflow.com/a/43985705/4952130
        // note that we know the ranges of characters coordinates will have:
        // [a-h], [1-8] which are similar in ascii/utf-8
        let row: u32 = coordinates.pop().unwrap() as u32 - '0' as u32;
        let col: u32 = (coordinates.pop().unwrap() as u32 - '0' as u32) - 96;
        col & 1 != row & 1
    }
}