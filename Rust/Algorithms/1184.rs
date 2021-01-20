impl Solution {
    pub fn distance_between_bus_stops(
        distance: Vec<i32>,
        start: i32,
        destination: i32,
    ) -> i32 {
        // sum to start, sum to dest, sum to end
        let (mut sts, mut std, mut ste) = (0, 0, 0);
        let mut idx = 1;
        distance.iter().for_each(|val| {
            if (idx <= start) {
                sts += val;
            }
            if (idx <= destination) {
                std += val;
            }
            ste += val;
            idx += 1;
        });
        // Calculate differences.
        let diff = if start > destination {
            sts - std
        } else {
            std - sts
        };
        let diff2 = ste - diff;
        // return min.
        if diff < diff2 {
            diff
        } else {
            diff2
        }
    }
}
