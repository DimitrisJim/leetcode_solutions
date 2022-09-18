impl Solution {
    pub fn arithmetic_triplets(nums: Vec<i32>, diff: i32) -> i32 {
        let mut pairs = 0;
        let end = nums.len();
        
        for i in 0..end - 2 {
            for j in i+1..end-1 {
                let mut numdiff = nums[j] - nums[i];
                if numdiff > diff {
                    break;
                }
                if numdiff == diff {
                    for k in j+1..end {
                        numdiff = nums[k] - nums[j];
                        if numdiff > diff {
                            break;
                        }
                        if numdiff == diff {
                            pairs += 1;
                        }
                    }
                }
            }
        }
        pairs
    }
}