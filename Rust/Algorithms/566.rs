use std::convert::TryFrom;

impl Solution {
    pub fn matrix_reshape(
        nums: Vec<Vec<i32>>,
        r: i32,
        c: i32,
    ) -> Vec<Vec<i32>> {
        let (nr, nc) =
            (usize::try_from(r).unwrap(), usize::try_from(c).unwrap());
        let (rows, cols) = (
            i32::try_from(nums.len()).unwrap(),
            i32::try_from(nums[0].len()).unwrap(),
        );
        if r * c > rows * cols {
            return nums;
        }

        let mut it = nums.into_iter().flatten();
        let mut result = Vec::with_capacity(nr);
        let mut inner = Vec::with_capacity(nc);
        for i in 0..nr {
            for j in 0..nc {
                inner.push(it.next().unwrap());
            }
            result.push(inner.clone());
            inner.clear();
        }
        result
    }
}
