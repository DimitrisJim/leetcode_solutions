impl Solution {
    pub fn sort_by_bits(mut arr: Vec<i32>) -> Vec<i32> {
        arr.sort();
        arr.sort_by_key(|k| k.count_ones());
        arr
    }
}
