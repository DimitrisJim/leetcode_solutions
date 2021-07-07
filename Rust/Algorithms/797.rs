impl Solution {
    pub fn all_paths_source_target(graph: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let mut paths = vec![];
        let last = (graph.len() - 1) as i32;
        let mut current_path = vec![];
        let mut to_visit = vec![(0, 0)];

        while to_visit.len() > 0 {
            let (level, node) = to_visit.pop().unwrap();

            if level < current_path.len() {
                current_path.truncate(level);
            }
            current_path.push(node);

            if node == last {
                // Could I not be cloning?
                paths.push(current_path.clone());
                continue;
            }

            for n in graph[node as usize].iter().cloned() {
                to_visit.push((level + 1, n));
            }
        }
        paths
    }
}
