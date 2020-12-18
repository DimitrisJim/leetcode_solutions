impl Solution {
    pub fn min_operations(logs: Vec<String>) -> i32 {
        let (mut in_main, mut depth) = (true, 0);
        logs.into_iter().for_each(|log| match &log[..] {
            "../" => {
                if !in_main {
                    depth -= 1;
                    if depth == 0 {
                        in_main = !in_main;
                    }
                }
            }
            "./" => {}
            _ => {
                depth += 1;
                if in_main {
                    in_main = !in_main;
                }
            }
        });
        depth
    }
}
