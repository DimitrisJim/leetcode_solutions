impl Solution {
    pub fn max_product(mut nums: Vec<i32>) -> i32 {
        // O(N) find max.
        let (max, idx) = match nums.iter().zip(0..nums.len()).max(){
                Some((a, b)) => (*a, b),
                None => (0, 0)
        };
        // O(1) swap end with idx.
        nums.swap_remove(idx);
        // O(N) find max (again)
        let max_two = nums.iter().max().expect("The unexpected");
        (max - 1) * (max_two - 1)        
    }
}
