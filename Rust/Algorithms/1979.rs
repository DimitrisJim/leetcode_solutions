impl Solution {
    pub fn find_gcd(nums: Vec<i32>) -> i32 {
        let (mut min, mut max) = (1001, 0);
        for num in nums {
            if num > max {
                max = num;
            }
            if num < min {
                min = num;
            }
        }
        
        while min != 0 {
            // ok in Rust 1.59.
            // (min, max) = (max % min, min);
            let temp = min;
            min = max % min;
            max = temp;
        }
        max
    }
}