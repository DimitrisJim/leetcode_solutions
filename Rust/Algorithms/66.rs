impl Solution {
    pub fn plus_one(mut digits: Vec<i32>) -> Vec<i32> {
        let mut i = digits.len() - 1;
        loop {
            if (digits[i] == 9) {
                digits[i] = 0;
                if i == 0 {
                    break;
                }
                i -= 1;
            } else {
                digits[i] += 1;
                break;
            }
        }
        if (i == 0 && digits[0] == 0) {
            digits.push(1);
            digits.into_iter().rev().collect()
        } else {
            digits
        }
    }
}
