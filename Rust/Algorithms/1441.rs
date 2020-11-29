impl Solution {
    pub fn build_array(target: Vec<i32>, n: i32) -> Vec<String> {
        let mut ops = Vec::new();
        let mut start = 0;
        for i in target {
            let diff = i - start - 1;
            if diff > 0 {
                for _i in 0..diff {
                    ops.push(String::from("Push"));
                    ops.push(String::from("Pop"));
                }
            }
            ops.push(String::from("Push"));
            start = i;
        }
        ops
    }
}
