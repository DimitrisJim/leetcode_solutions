use std::collections::HashMap;

impl Solution {
    pub fn find_lucky(arr: Vec<i32>) -> i32 {
        let mut Counter = HashMap::new();

        for x in arr.into_iter() {
            let value = Counter.get(&x).cloned().unwrap_or(0);
            Counter.insert(x, if value == 0 { 1 } else { value + 1 });
        }
        let mut largest = -1;
        for (k, v) in Counter.into_iter() {
            if (k == v && k > largest) {
                largest = k;
            }
        }
        largest
    }
}
