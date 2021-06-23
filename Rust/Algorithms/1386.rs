use std::collections::HashMap;

impl Solution {
    pub fn get_kth(lo: i32, hi: i32, k: i32) -> i32 {
        let mut cache = HashMap::with_capacity((hi - lo) as usize);
        fn power_x(x: i32, cache: &mut HashMap<i32, i32>) -> i32 {
            if x == 1 {
                return 1;
            }
            if cache.contains_key(&x) {
                return *cache.get(&x).unwrap();
            }
            let value = if x & 1 == 1 {
                power_x(3 * x + 1, cache)
            } else {
                power_x(x / 2, cache)
            };
            cache.insert(x, value + 1);
            value + 1
        };
        let mut powers = Vec::with_capacity((hi - lo) as usize);
        for i in lo..=hi {
            powers.push([i, power_x(i, &mut cache)]);
        }
        powers.sort_by_key(|x| x[1]);
        return powers[(k - 1) as usize][0];
    }
}
