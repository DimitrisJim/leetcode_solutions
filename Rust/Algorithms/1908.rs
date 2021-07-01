impl Solution {
    pub fn can_be_increasing(nums: Vec<i32>) -> bool {
        let mut removed = false;
        let (mut i, end) = (0, nums.len() - 1);
        while (i < end) {
            let a = nums[i];
            let b = nums[i + 1];
            if (a >= b) {
                // if we've removed before, return.
                if (removed) {
                    return false;
                }
                removed = !removed;
                // Need to check neighbours of a, b.
                // if b <= than neighbour of a, b is the
                // odd one out and should be removed.
                if (i > 0 && b <= nums[i - 1]) {
                    // but if a is larger than neighbour of
                    // b, there's nothing we can do.
                    if (i + 2 < nums.len() && a >= nums[i + 2]) {
                        return false;
                    }
                    i += 2;
                    continue;
                }
            }
            i += 1;
        }
        true
    }
}
