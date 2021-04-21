impl Solution {
    pub fn summary_ranges(nums: Vec<i32>) -> Vec<String> {
        if (nums.len() == 0) {
            return vec![];
        }

        let mut results = vec![];
        // Might overflow with i32.
        let mut start = nums[0] as i64;
        let mut end = start;
        let mut rng = String::from("");
        for num in nums.iter() {
            // range ended.
            if ((*num as i64) != end){
                rng.push_str(&start.to_string());
                if start != (end - 1) {
                    rng.push_str("->");
                    rng.push_str(&(end - 1).to_string());
                }
                // Not sure if cloning here is better than
                // creating a string during each iteration.
                results.push(rng.clone());
                start = *num as i64;
                end = start;
                rng.clear()
            }
            end += 1;
        }
        // A final number was left in nums.
        if start == *nums.last().unwrap() as i64 {
            results.push(String::from(start.to_string()));
        }
        // we finished while going through a range.
        else if start != (end - 1) {
            rng.push_str(&start.to_string());
            rng.push_str("->");
            rng.push_str(&(end - 1).to_string());
            results.push(rng);
        }
        results
    }
}