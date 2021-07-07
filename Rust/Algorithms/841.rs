use std::collections::HashSet;


impl Solution {
    pub fn can_visit_all_rooms(rooms: Vec<Vec<i32>>) -> bool {
        let mut visited = HashSet::with_capacity(rooms.len());
        let mut to_visit: Vec<i32> = rooms[0].iter().cloned().collect();
        
        visited.insert(0);
        while to_visit.len() > 0 {
            let v = to_visit.pop().unwrap();
            if !visited.contains(&v) {
                to_visit.extend_from_slice(&rooms[v as usize]);
                visited.insert(v);
            }
        }
        visited.len() == rooms.len()
    }
}