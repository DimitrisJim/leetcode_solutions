impl Solution {
    pub fn remove_element(nums: &mut Vec<i32>, val: i32) -> i32 {
        let mut start = 0;
        let mut finish = nums.len();
        
        while start < finish {
            if nums[start] == val {
                let end = nums.pop().unwrap();
                finish -= 1;
                if start < finish {
                    nums[start] = end;
                }
            } else {
                start += 1;
            }
        }
        finish as i32
    }
}