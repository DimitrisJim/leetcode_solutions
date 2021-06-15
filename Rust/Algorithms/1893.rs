impl Solution {
    pub fn is_covered(mut ranges: Vec<Vec<i32>>, mut left: i32, mut right: i32) -> bool {
        ranges.sort_by_key(|rng| rng[1]);
        let mut i = 0;
        while left <= right && i < ranges.len() {
            let l = ranges[i][0];
            let r = ranges[i][1];
            if l <= left && left <= r {
                left = r + 1;
            }
            if l <= right && right <= r {
                right = l - 1;
            }
            i += 1;
        }
        left > right
    }
}