use std::collections::HashMap;
use std::iter::FromIterator;

impl Solution {
    pub fn relative_sort_array(
        mut arr1: Vec<i32>,
        arr2: Vec<i32>,
    ) -> Vec<i32> {
        let mut order =
            HashMap::<i32, i32>::from_iter(arr2.into_iter().zip(0..));
        arr1.sort_unstable_by_key(|value| {
            order.get(value).unwrap_or(&(1000 + value)).to_owned()
        });
        arr1
    }
}
