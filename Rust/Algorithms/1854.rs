impl Solution {
    pub fn maximum_population(logs: Vec<Vec<i32>>) -> i32 {
        // hold the counts for each year. Year can be found by
        let mut counts = vec![0; 101];

        // Fill in counts for each range.
        let mut max = 0;
        for pair in logs {
            // subtract 1950 to go from [1950, 2050] range
            // to [0, 100] range. (both are inclusive).
            let start = ((pair[0] - 1950) as usize);
            let end = ((pair[1] - 1950) as usize);
            for i in start..end {
                counts[i] += 1;
                if (max < counts[i]) {
                    max = counts[i];
                }
            }
        }
        // find min index in counts with value == max.
        let mut index = 0;
        for i in 0..counts.len() {
            if (counts[i] == max) {
                index = i;
                break;
            }
        }
        // from index => years.
        (index as i32) + 1950
    }
}
