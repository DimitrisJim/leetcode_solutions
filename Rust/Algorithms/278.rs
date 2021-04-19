// The API isBadVersion is defined for you.
// isBadVersion(versions:i32)-> bool;
// to call it use self.isBadVersion(versions)

impl Solution {
    pub fn first_bad_version(&self, n: i32) -> i32 {
        let mut start: u32 = 0;
        let mut end = n as u32;
        while (end - start != 1) {
            let mid = (start + end) / 2;
            if self.isBadVersion(mid as i32) {
                end = mid;
            } else {
                start = mid;
            }
        }
        // We know its positive.
        end as i32
    }
}