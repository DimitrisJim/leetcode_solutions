impl Solution {
    pub fn num_identical_pairs(nums: Vec<i32>) -> i32 {
        let mut mnums = nums.to_owned();
        // need mut handle to sort.
        mnums.sort();
        
        // 1 + 2 + 3 + ... + n
        let sn = |n| (n * (n + 1)) / 2;
        let (mut num_pairs, mut num) = (0, 0);
        
        // Go through vector.
        for i in 1..mnums.len(){
            // find len of group.
            if (mnums[i] == mnums[i-1]){
                num += 1;
            }
            // add sum and start again.
            else {
                num_pairs += sn(num);
                num = 0;
            }
        }
        // add leftovers.
        num_pairs += sn(num);
        return num_pairs;
    }
}
