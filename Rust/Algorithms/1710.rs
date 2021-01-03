impl Solution {
    pub fn maximum_units(
        mut box_types: Vec<Vec<i32>>,
        mut truck_size: i32,
    ) -> i32 {
        box_types.sort_unstable_by_key(|k| k[1]);

        let mut count = 0;
        for i in box_types.into_iter().rev() {
            let num_b = i[0];
            let num_u = i[1];
            if num_b <= truck_size {
                count += num_b * num_u;
                truck_size -= num_b;
                if truck_size == 0 {
                    return count;
                }
            } else {
                return count + truck_size * num_u;
            }
        }
        count
    }
}
