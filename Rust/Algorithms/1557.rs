impl Solution {
    pub fn find_smallest_set_of_vertices(
        n: i32,
        edges: Vec<Vec<i32>>,
    ) -> Vec<i32> {
        let mut counts = vec![0; n as usize];
        // let mut isolated = vec![];
        for dest in edges.iter().map(|p| p[1]) {
            counts[dest as usize] += 1;
        }
        // filter map is cool.
        counts
            .iter()
            .enumerate()
            .filter_map(
                |(i, &v)| {
                    if v == 0 {
                        Some(i as i32)
                    } else {
                        None
                    }
                },
            )
            .collect()
    }
}
