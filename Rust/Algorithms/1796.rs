impl Solution {
    pub fn second_highest(s: String) -> i32 {
        let mut max = ' ';
        let mut second_max = ' ';
        for i in s.chars().filter(|c| char::is_ascii_digit(c)) {
            if i > max {
                if max > second_max {
                    second_max = max;
                }
                max = i;
            } else if i > second_max && i != max {
                second_max = i;
            }
        }
        if second_max == ' ' {
            -1
        } else {
            second_max.to_digit(10).unwrap() as i32
        }
    }
}
