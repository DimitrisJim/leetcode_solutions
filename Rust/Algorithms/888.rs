use std::collections::HashSet;

impl Solution {
    pub fn fair_candy_swap(a: Vec<i32>, b: Vec<i32>) -> Vec<i32> {
        let (sumA, sumB) = (a.iter().sum::<i32>(), b.iter().sum::<i32>());
        let a_larger = sumA > sumB;
        let (max, min) = if a_larger {
            (a, b.iter().collect::<HashSet<_>>())
        } else {
            (b, a.iter().collect::<HashSet<_>>())
        };

        let diff = (sumA - sumB).abs() / 2;
        for i in max {
            let j = i - diff;
            if min.contains(&j) {
                return if a_larger { vec![i, j] } else { vec![j, i] };
            }
        }
        // unreachable.
        vec![]
    }
}
