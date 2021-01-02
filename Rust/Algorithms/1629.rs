impl Solution {
    pub fn slowest_key(
        release_times: Vec<i32>,
        keys_pressed: String,
    ) -> char {
        let (mut max_indices, mut max) = (vec![0], release_times[0]);
        let keys: Vec<_> = keys_pressed.chars().collect();
        for i in 1..release_times.len() {
            let diff = release_times[i] - release_times[i - 1];
            if diff > max {
                max_indices.clear();
                max_indices.push(i);
                max = diff;
            } else if diff == max {
                max_indices.push(i);
            }
        }
        max_indices.into_iter().map(|i| keys[i]).max().unwrap()
    }
}
