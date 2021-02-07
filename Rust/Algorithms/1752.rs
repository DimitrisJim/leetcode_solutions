impl Solution {
    pub fn check(nums: Vec<i32>) -> bool {
        let (length, start) = (nums.len(), nums[0]);
        for i in 1..length {
            // posible point of rotation
            if (nums[i - 1] > nums[i]) {
                for j in i + 1..length {
                    // Make sure we still have non-decreasing order
                    // and none are larger than start (which would
                    // mean that before rotation, nums[i-1] < nums[i] for
                    // nums[i-1] == start.)
                    if (nums[j - 1] > nums[j] || start < nums[j]) {
                        return false;
                    }
                }
            }
        }
        true
    }
}
