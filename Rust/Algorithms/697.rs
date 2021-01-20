use std::collections::HashMap;

impl Solution {
    #[inline]
    fn make_counter(nums: &Vec<i32>) -> HashMap<i32, i32> {
        let mut Counter = HashMap::new();
        for i in nums.iter() {
            match Counter.get_mut(i) {
                Some(val) => {
                    *val += 1;
                }
                None => {
                    Counter.insert(*i, 1);
                }
            }
        }
        Counter
    }

    // Go from start and end and find leftmost and rightmost
    // occurence of each value in items. The result is the
    // min of (rightmost-leftmost)
    #[inline]
    fn find_min(items: &Vec<i32>, nums: &Vec<i32>, max_deg: i32) -> i32 {
        let mut min_length = nums.len();
        for i in items.into_iter() {
            let (mut start, mut end) = (0, nums.len() - 1);
            while start < end {
                let (s, e) = (nums[start], nums[end]);
                if s != *i {
                    start += 1;
                }
                if e != *i {
                    end -= 1;
                }
                if s == *i && e == *i {
                    // Found bounds, check if it's smaller than
                    // min_length.
                    let diff = end - start + 1;
                    // Can bail if we find a diff == max degree,
                    // no other diff will be smaller.
                    if (diff as i32) == max_deg {
                        return max_deg;
                    }
                    if diff < min_length {
                        min_length = diff;
                    }
                    break;
                }
            }
        }
        min_length as i32
    }

    pub fn find_shortest_sub_array(nums: Vec<i32>) -> i32 {
        // Build counts from nums.
        let mut counts = Solution::make_counter(&nums);

        // Find max degree of nums and the elements that have
        // that max degree.
        let mut max_deg = -1;
        let mut items = vec![];
        for (key, val) in counts.into_iter() {
            if val > max_deg {
                items.clear();
                items.push(key);
                max_deg = val;
            } else if val == max_deg {
                items.push(key);
            }
        }
        // Special case: unique elements in nums.
        if max_deg == 1 {
            return 1;
        }
        Solution::find_min(&items, &nums, max_deg)
    }
}
