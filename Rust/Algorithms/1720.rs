impl Solution {
    pub fn decode(encoded: Vec<i32>, first: i32) -> Vec<i32> {
        let mut result = Vec::with_capacity(encoded.len() + 1);
        result.push(first);

        for i in encoded {
            result.push(result.last().unwrap() ^ i);
        }
        result
    }
}
