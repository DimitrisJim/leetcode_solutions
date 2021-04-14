impl Solution {
    pub fn merge(nums1: &mut Vec<i32>, m: i32, nums2: &mut Vec<i32>, n: i32) {
        // We know nums2 is n and nums1 is m + n. So this won't panic.
        nums1[m as usize..].copy_from_slice(&nums2);
        nums1.sort();
    }
}