impl Solution {
    pub fn get_lucky(s: String, mut k: i32) -> i32 {
        // Populate with digits for each char of s.
        let mut nums = vec![];
        for val in s.as_bytes().into_iter().map(|c| (c - 96) as u32) {
            if (val < 10) {
                nums.push(val);
            } else {
                nums.push(val / 10);
                nums.push(val % 10);
            }
        }

        // Continuously reduce until k == 1 or length == 1.
        // k > 1 because final return performs a conversion.
        while k > 1 && nums.len() > 1 {
            let sum = nums.into_iter().sum::<u32>().to_string();
            nums = sum.chars().map(|c| c.to_digit(10).unwrap()).collect();
            k -= 1;
        }
        // Doesn't really come close to value where u32 to i32 would overflow
        return nums.into_iter().sum::<u32>() as i32;
    }
}
