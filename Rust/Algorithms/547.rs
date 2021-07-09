impl Solution {
    pub fn find_circle_num(is_connected: Vec<Vec<i32>>) -> i32 {
        let mut visited = vec![0; is_connected.len() + 1];
        let mut count = 0;
        for i in 1..is_connected.len() + 1 {
            if visited[i] == 1 {
                continue;
            }
            // Seen new component, increase count.
            visited[i] = 1;
            count += 1;

            // dfs on i.
            let mut visit = vec![i];
            while visit.len() > 0 {
                let node = visit.pop().unwrap();
                // Is this an unreadable mess?
                (1..is_connected.len() + 1)
                    .zip(&is_connected[node - 1])
                    .filter(|(_, value)| **value == 1)
                    .for_each(|(index, value)| {
                        if !(visited[index] == 1 || index == node) {
                            visited[index] = 1;
                            visit.push(index);
                        }
                    });
            }
        }
        count
    }
}
