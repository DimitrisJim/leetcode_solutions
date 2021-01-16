use std::collections::HashSet;

impl Solution {
    pub fn is_path_crossing(path: String) -> bool {
        let mut points: HashSet<(i32, i32)> =
            vec![(0, 0)].into_iter().collect();
        let mut pos = (0, 0);

        for d in path.chars() {
            pos = match d {
                'W' => (pos.0, pos.1 + 1),
                'E' => (pos.0, pos.1 - 1),
                'N' => (pos.0 + 1, pos.1),
                _ => (pos.0 - 1, pos.1),
            };
            if points.contains(&pos) {
                return true;
            } else {
                points.insert(pos);
            }
        }
        false
    }
}
