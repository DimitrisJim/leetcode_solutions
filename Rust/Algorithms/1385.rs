impl Solution {
    pub fn find_the_distance_value(
        arr1: Vec<i32>,
        arr2: Vec<i32>,
        d: i32,
    ) -> i32 {
        let mut count = 0;
        for i in arr1 {
            let (top, bottom) = ((i + d), (i - d));
            // Need iter, on into_iter (default), moves.
            for j in arr2.iter() {
                if top >= *j && *j >= bottom {
                    count -= 1;
                    break;
                }
            }
            count += 1;
        }
        count
    }
}
