use std::collections::VecDeque;
use std::convert::TryFrom;

impl Solution {
    pub fn count_students(
        students: Vec<i32>,
        sandwiches: Vec<i32>,
    ) -> i32 {
        let mut st: VecDeque<i32> = students.into_iter().collect();
        let mut sa: VecDeque<i32> = sandwiches.into_iter().collect();
        let mut i = 0;

        while i != st.len() {
            if st.front() == sa.front() {
                st.pop_front();
                sa.pop_front();
                i = 0;
            } else {
                st.rotate_left(1);
                i += 1;
            }
        }
        i32::try_from(st.len()).unwrap()
    }
}
