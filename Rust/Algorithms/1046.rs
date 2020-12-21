use std::collections::BinaryHeap;

impl Solution {
    pub fn last_stone_weight(stones: Vec<i32>) -> i32 {
        let mut heap = BinaryHeap::with_capacity(stones.len());

        for el in stones.into_iter() {
            heap.push(el);
        }
        loop {
            let (e1, e2) = (heap.pop(), heap.pop());
            match e1 {
                None => {
                    return 0;
                }
                Some(v1) => match e2 {
                    None => {
                        return v1;
                    }
                    Some(v2) => {
                        let diff = v1 - v2;
                        if diff != 0 {
                            heap.push(diff);
                        }
                    }
                },
            }
        }
        // unreachable.
        0
    }
}
