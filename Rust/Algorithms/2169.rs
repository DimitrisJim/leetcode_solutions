impl Solution {
    pub fn count_operations(mut num1: i32, mut num2: i32) -> i32 {
        let mut ops = 0;
        while num1 > 1 && num2 > 1 {
            if num1 > num2 {
                num1 -= num2;
            } else {
                num2 -= num1;
            }
            ops += 1;
        }
        if num1 == 0 || num2 == 0 {
            ops
        } else {
            ops + num2 + num1 - 1
        }
    }
}