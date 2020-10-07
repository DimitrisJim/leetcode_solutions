impl Solution {
    pub fn running_sum(nums: Vec<i32>) -> Vec<i32> {
        let mut res = vec![];
        let mut running_sum: i32 = 0;
        for i in nums.iter(){
            running_sum += i;
            // Cloning is cheap.
            res.push(running_sum.clone());
        }
        return res;
    }
}
