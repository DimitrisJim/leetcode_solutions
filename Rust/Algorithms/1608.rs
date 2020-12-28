use std::convert::TryFrom;

impl Solution {
    pub fn special_array(nums: Vec<i32>) -> i32 {
        let length = nums.len();
        for i in 1..length + 1 {
            let mut cand = 0;
            for j in 0..length {
                let el = usize::try_from(nums[j]).unwrap();
                if el >= i {
                    cand += 1;
                    if cand > i {
                        break;
                    }
                    continue;
                }
                if cand + length - j < i {
                    break;
                }
            }
            if cand == i {
                return i32::try_from(i).unwrap();
            }
        }
        -1
    }
}
