impl Solution {
    pub fn find_numbers(nums: Vec<i32>) -> i32 {
        let mut s = 0;
        for j in nums{
            if (
                ((9 < j) && (j < 100)) || 
                ((999 < j) && (j < 10000)) || 
                (j == 100000)
            ){
                s += 1;
            }
        }
        s
    }
}
