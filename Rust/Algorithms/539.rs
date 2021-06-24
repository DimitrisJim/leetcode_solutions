use std::cmp::min;
use std::collections::HashSet;

impl Solution {
    pub fn find_min_difference(time_points: Vec<String>) -> i32 {
        // Can use a set to hold values. This way we can bail early
        // if we encounter a duplicate.
        let mut timepoints = HashSet::new();
        for d in time_points {
            // fancy way to transform iterator to (i32, i32)?
            let time = d
                .split(":")
                .map(|x| x.parse::<i32>().unwrap())
                .collect::<Vec<_>>();
            let (h, m) = (time[0], time[1]);
            let v = if (h > 0) {
                h
            } else {
                if m == 0 {
                    0
                } else {
                    24
                }
            } * 60
                + m;
            if (timepoints.contains(&v)) {
                return 0;
            }
            timepoints.insert(v);
        }
        let mut timepoints = timepoints.into_iter().collect::<Vec<_>>();
        timepoints.sort_unstable();

        let mut min_diff = 2400;
        for i in 0..timepoints.len() - 1 {
            min_diff = min(min_diff, timepoints[i + 1] - timepoints[i]);
        }
        // check min time + 1440 (24 * 60) - max_time to see if we have a smaller
        // value on the edges.
        min(min_diff, timepoints[0] + 1440 - timepoints.last().unwrap())
    }
}
