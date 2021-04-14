impl Solution {
    pub fn k_length_apart(nums: Vec<i32>, k: i32) -> bool {
        let mut diff = k;
        
        match nums.iter().position(|&x| x == 1){
            Some(start) => {
                for i in start+1..nums.len() {
                    if nums[i] == 1 {
                        if diff > 0 {
                            return false;
                        }
                        diff = k;
                    } else {
                        diff -= 1;
                    }
                }
                true
            },
            None => true
        }
    }
}