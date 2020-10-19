impl Solution {
    pub fn sort_array_by_parity(mut a: Vec<i32>) -> Vec<i32> {
        // Could also use deque for O(N) exec but also O(N) space
        a.sort_unstable_by_key(|i| i & 1);
        a
    }
}
