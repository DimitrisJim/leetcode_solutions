use std::collections::HashMap;

impl Solution {
    pub fn max_number_of_balloons(text: String) -> i32 {
        let mut counter = HashMap::new();
        let b = String::from("balloon");

        for c in text.chars() {
            match counter.get_mut(&c) {
                None => {
                    counter.insert(c, 1);
                }
                Some(count) => *count += 1,
            }
        }
        let mut times = 0;
        loop {
            for c in b.chars() {
                match counter.get_mut(&c) {
                    None => {
                        return times;
                    }
                    Some(count) => {
                        if *count == 0 {
                            return times;
                        }
                        *count -= 1;
                    }
                }
            }
            times += 1;
        }
        times
    }
}
