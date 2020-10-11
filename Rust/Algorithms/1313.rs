impl Solution {
    pub fn decompress_rl_elist(nums: Vec<i32>) -> Vec<i32> {
        let mut res = Vec::new();
        let mut i = 0;
        
        while i < nums.len(){
            let mut j = 0;
            while j < nums[i]{
                res.push(nums[i+1]);
                j += 1;
            }
            i += 2;
        }
        res
    }
}
