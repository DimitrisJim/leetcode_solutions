impl Solution {
    pub fn sum_zero(n: i32) -> Vec<i32> {
        let mut v = Vec::with_capacity(n as usize);
        if n & 1 == 1 {
            v.push(0);
        }
        for i in 1..((n/2) + 1){
            v.push(i);
            v.push(-i);
        }
        v
    }
}
