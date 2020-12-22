use std::iter::FromIterator;

impl Solution {
    pub fn reformat_number(number: String) -> String {
        let num = String::from_iter(number.matches(char::is_numeric));
        let mut result = Vec::new();
        let length = num.len();

        let (mut left, mut repeat) = (length, 0);
        while left > 4 {
            left -= 3;
            repeat += 1;
        }
        for i in (0..repeat * 3).step_by(3) {
            result.push(&num[i..i + 3]);
        }
        match left {
            4 => {
                result.push(&num[length - 4..length - 2]);
                result.push(&num[length - 2..]);
            }
            _ => {
                result.push(&num[length - left..]);
            }
        }
        result.join("-")
    }
}
