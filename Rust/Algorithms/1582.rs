use std::collections::HashSet;

impl Solution {
    pub fn num_special(mat: Vec<Vec<i32>>) -> i32 {
        let mut occupied_columns = HashSet::new();
        let (rows, columns) = (mat.len(), mat[0].len());
        let mut special = 0;

        for r in 0..rows {
            let mut bail = false;
            for c in 0..columns {
                if mat[r][c] == 1 {
                    if occupied_columns.contains(&c) {
                        break;
                    }

                    // Check the rest of the row:
                    for k in c + 1..columns {
                        if mat[r][k] == 1 {
                            occupied_columns.insert(k);
                            bail = true;
                            break;
                        }
                    }
                    if bail {
                        occupied_columns.insert(c);
                        break;
                    }
                    // Check all other rows:
                    for k in 0..rows {
                        if mat[k][c] == 1 && k != r {
                            occupied_columns.insert(c);
                            bail = true;
                            break;
                        }
                    }
                    if bail {
                        break;
                    }

                    // done:
                    occupied_columns.insert(c);
                    special += 1;
                }
            }
        }
        special
    }
}
