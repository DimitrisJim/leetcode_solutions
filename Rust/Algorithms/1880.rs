impl Solution {
    pub fn is_sum_equal(first_word: String, second_word: String, target_word: String) -> bool {
        let asNum = |s: &String| {
            let mut length = (s.len()-1) as u32;
            let mut value = 0;
            for digit in s.as_bytes().iter().map(|x| x - 97) {
                if (digit != 0) {
                    value += (10u32).pow(length) * digit as u32;
                }
                length -= 1;
            }
            value
        };
        asNum(&first_word) + asNum(&second_word) == asNum(&target_word)
    }
}