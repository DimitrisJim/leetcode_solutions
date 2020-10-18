impl Solution {
    pub fn odd_cells(n: i32, m: i32, indices: Vec<Vec<i32>>) -> i32 {
        // Handle 1 x 1 case.
        if (n == 1) && (m == 1) {
            return 0;
        }
        
        // Keep track of odd cols/rows
        let mut rows: i64 = 0;
        let mut cols: i64 = 0;
        for subvec in indices{
            rows ^= (1 << subvec[0] as i64);
            cols ^= (1 << subvec[1] as i64);
        }
        // Count # of odd rows/cols.
        let mut lr: i32 = 0;
        let mut lc: i32 = 0;
        while (rows > 0){
            lr = (lr + (rows & 1) as i32);
            rows >>= 1;
        }
        while (cols > 0){
            lc = (lc + (cols & 1) as i32);
            cols >>= 1;
        }
        
        // Handle edge cases 2 x 1 and 1 x 2
        if (((n == 1) && (m == 2)) || ((n == 2) && (m == 1))){
            if (lr >= lc){
                return lr;   
            }
            return lc;
        }
        // Handle edge case 2 x 2 matrix.
        if((n == 2) && (m == 2)){
            if (((lr == 2) && (lc == 2)) || ((lr == 0) && (lc == 0))){
                return 0;
            }else if (((lr == 0) && (lc == 2)) || ((lr == 2) && (lc == 0))){
                return 4;
            }
            return 2;
        }
        // Handle edge case where either m or n is 2.
        if ((n == 2) || (m == 2)){
            if (n == 2) { 
                return (m - lc) * lr; 
            }
            return (n - lr) * lc;
        }
        // Sum according to # of odd rows/cols
        (m - lc) * lr + (n - lr) * lc
    }
}
