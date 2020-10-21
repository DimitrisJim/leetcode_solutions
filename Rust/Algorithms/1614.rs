impl Solution {
    pub fn max_depth(s: String) -> i32 {
        let (mut max, mut depth) = (0, 0);
        for c in s.chars() {
            match c {
                '(' => {
                        depth += 1;
                        if depth > max {
                            max = depth;
                        }
                },
                ')' => {
                    depth -= 1;    
                },
                _ => (),
            }
        }
        max
    }
}
