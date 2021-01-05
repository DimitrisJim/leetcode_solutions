impl Solution {
    pub fn largest_perimeter(mut A: Vec<i32>) -> i32 {
        A.sort_unstable();

        for i in (2..A.len()).rev() {
            let (a, b, c) = (A[i], A[i - 1], A[i - 2]);
            if a + b > c && b + c > a && c + a > b {
                return a + b + c;
            }
        }
        0
    }
}
