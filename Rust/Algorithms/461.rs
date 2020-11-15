impl Solution {
    pub fn hamming_distance(x: i32, y: i32) -> i32 {
        let mut diff = x ^ y;
        let mut count = 0;
        while (diff > 0) {
            count += diff & 1;
            diff >>= 1;
        }
        count
    }
}
