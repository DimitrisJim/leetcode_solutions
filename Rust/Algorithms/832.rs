impl Solution {
    pub fn flip_and_invert_image(a: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        a
        .iter()
        .map(|x| {                    // map through sub vectors
            x.iter()
            .map(|x| x ^ 1).rev()     // xor with 1 (flip)
            .collect::<Vec<i32>>()    // reverse
            }
        ).collect()                   // collect back to Vec<Vec<i32>>
    }
}
