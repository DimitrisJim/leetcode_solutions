impl Solution {
    pub fn add_digits(num: i32) -> i32 {
        if num == 0 {
            return 0;
        }
        let result = num % 9;
        if result == 0 {
            9
        } else {
            result
        }
    }
}
