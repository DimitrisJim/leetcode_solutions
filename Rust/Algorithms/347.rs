use std::collections::{BinaryHeap, HashMap};
use std::cmp::Ordering;

#[derive(Eq)]
struct Pair {
    key: i32,
    value: i32,
}

// Boilerplate for Heap. Implement Ord for the Pair
// and reverse its result.  
impl Ord for Pair {
    fn cmp(&self, other: &Self) -> Ordering {
        // flip result. (What Reverse probably does?)
        match self.value.cmp(&other.value) {
            Ordering::Less => Ordering::Greater,
            Ordering::Greater => Ordering::Less,
            Ordering::Equal => Ordering::Equal,
        }
    }
}

impl PartialOrd for Pair {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}

impl PartialEq for Pair {
    fn eq(&self, other: &Self) -> bool {
        self.key == other.key
    }
}

impl Solution {
    pub fn top_k_frequent(nums: Vec<i32>, k: i32) -> Vec<i32> {
        let mut freqs = HashMap::new();
        let mut pq = BinaryHeap::new();
        
        // Count occurences.
        for value in nums {
            let counter = freqs.entry(value).or_insert(0);
            *counter += 1;
        }

        // Insert in Heap.
        for (key, value) in freqs {
            // If we haven't filled up PriorityQueue. Insert
            // unconditionally.
            if pq.len() < k as usize {
                pq.push(Pair {key, value});
            // Else, only insert if we have a value larger than the current min.
            } else if pq.peek().unwrap().value < value {
                pq.pop();
                pq.push(Pair {key, value});
            }
        }
        
        // Return keys.
        pq.iter().map(|p| p.key).collect()
    }
}