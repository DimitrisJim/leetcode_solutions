use std::cmp::min;

impl Solution {
    pub fn min_cost_climbing_stairs(cost: Vec<i32>) -> i32 {
        let mut table = vec![2 << 20; cost.len() + 2];
        table[0] = 0;

        for i in 1..table.len() {
            let prev = table[i - 1];
            table[i] = min(
                table[i],
                prev + if (i < cost.len()) { cost[i - 1] } else { 0 },
            );
            let j = i + 1;
            if (j < table.len()) {
                table[j] = min(
                    table[j],
                    prev + if (i < cost.len()) { cost[i] } else { 0 },
                );
            }
        }
        // return final element.
        table[table.len() - 1]
    }
}
