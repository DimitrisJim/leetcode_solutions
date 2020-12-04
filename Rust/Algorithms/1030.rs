impl Solution {
    pub fn all_cells_dist_order(
        r: i32,
        c: i32,
        r0: i32,
        c0: i32,
    ) -> Vec<Vec<i32>> {
        // Add initial value.
        let mut result = vec![vec![r0, c0]];

        // Find limits for creating addition/subtraction ammounts.
        let Rlim = if ((r - r0) >= r0) { (r - r0) } else { r0 };
        // for both c and r. This way we reduce a couple of iterations.
        let Clim = if ((c - c0) >= c0) { (c - c0) } else { c0 };
        // hold the ammounts to sum/subtract r0, c0 by.
        let mut indices = Vec::new();
        for i in 0..Rlim + 1 {
            for j in 0..Clim + 1 {
                indices.push((i, j));
            }
        }
        // Result needs to be sorted, sort here.
        indices.sort_by_key(|el| el.0 + el.1);
        // Skip first entry (see result).
        indices.into_iter().skip(1).for_each(|x| {
            // Basically: Try and add and subtract, if we are in
            // the correct bounds [0, r) or [0, c), we can add the pair.
            // if j > 0 and if i > 0 guard against't cases where
            // because i, j might be zero we might add a pair twice.
            let (i, j) = x;
            let (rpi, rmi, cpj, cmj) = (r0 + i, r0 - i, c0 + j, c0 - j);
            if rmi >= 0 {
                if cmj >= 0 {
                    result.push(vec![rmi, cmj]);
                }
                if j > 0 && cpj < c {
                    result.push(vec![rmi, cpj]);
                }
            }
            if rpi < r && i > 0 {
                if cpj < c {
                    result.push(vec![rpi, cpj]);
                }
                if j > 0 && cmj >= 0 {
                    result.push(vec![rpi, cmj]);
                }
            }
        });
        result
    }
}
