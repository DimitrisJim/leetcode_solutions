impl Solution {
    pub fn search_matrix(matrix: Vec<Vec<i32>>, target: i32) -> bool {
        for row in matrix {
            if &target > row.last().unwrap() {
                continue;
            }
            // try and find the element.
            if row.binary_search(&target).is_ok() {
                return true;
            }
        }
        false
    }
}
