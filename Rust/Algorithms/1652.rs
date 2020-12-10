impl Solution {
    pub fn decrypt(code: Vec<i32>, k: i32) -> Vec<i32> {
        let len = code.len();
        let mut result = vec![0; len];
        if k != 0 {
            for i in 0..len {
                let mut sum = 0;
                for j in 0..k.abs() {
                    sum += if k < 0 {
                        let x = ((i as i32) - 1 - j);
                        code[if x >= 0 {
                            x as usize
                        } else {
                            ((len as i32 + x) as usize)
                        }]
                    } else {
                        code[(i + 1 + j as usize) % len]
                    }
                }
                result[i] = sum;
            }
        }
        result
    }
}
