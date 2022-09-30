impl Solution {
    pub fn sort_people(names: Vec<String>, heights: Vec<i32>) -> Vec<String> {
        let mut people: Vec<(_, _)> = heights.into_iter().zip(names.into_iter()).collect();
        people.sort_by_key(|k| k.0);
        
        people.into_iter().rev().map(|k| k.1).collect()
    }
}