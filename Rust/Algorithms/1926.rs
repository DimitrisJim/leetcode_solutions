use std::collections::{HashSet, VecDeque};

impl Solution {
    pub fn nearest_exit(maze: Vec<Vec<char>>, entrance: Vec<i32>) -> i32 {
        let mut to_visit = VecDeque::new();
        let (rows, cols) = (maze.len() - 1, maze[0].len() - 1);
        let mut visited = HashSet::new();
        to_visit
            .push_back((0, (entrance[0] as usize, entrance[1] as usize)));

        while (to_visit.len() > 0) {
            let (mut length, p) = to_visit.pop_front().unwrap();
            if (visited.contains(&p)) {
                continue;
            }
            visited.insert(p);
            let (r, c) = p;
            // check if this is exit from maze
            if ((r == 0 || r == rows) || (c == 0 || c == cols)) {
                // not at starting position.
                if (length > 0) {
                    return length;
                }
            }
            // If not, add any directions possible.
            // up
            length += 1;
            if (r < rows && maze[r + 1][c] == '.') {
                to_visit.push_back((length, (r + 1, c)));
            }
            // down
            if (r > 0 && maze[r - 1][c] == '.') {
                to_visit.push_back((length, (r - 1, c)));
            }
            // right
            if (c < cols && maze[r][c + 1] == '.') {
                to_visit.push_back((length, (r, c + 1)));
            }
            // left
            if (c > 0 && maze[r][c - 1] == '.') {
                to_visit.push_back((length, (r, c - 1)));
            }
        }
        -1
    }
}
