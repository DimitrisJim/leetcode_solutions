use std::collections::HashSet;

impl Solution {
    pub fn lucky_numbers(matrix: Vec<Vec<i32>>) -> Vec<i32> {
        // preset the capacity.
        let mut mins = HashSet::with_capacity(matrix.len());
        let mut maxes = vec![0; matrix[0].len()];

        // Go through rows and calculate mins/maxes.
        for row in matrix {
            let mut min = row[0];
            for (index, el) in row.iter().enumerate() {
                if *el < min {
                    min = *el;
                }
                if maxes[index] < *el {
                    maxes[index] = *el;
                }
            }
            mins.insert(min);
        }
        // or this:
        // maxes.iter().filter(|x| mins.contains(x)).cloned().collect()
        mins
            // Create a set out of maxes to intersect with.
            .intersection(&maxes.iter().cloned().collect())
            // collect the results and return.
            .cloned()
            .collect()
    }
}
