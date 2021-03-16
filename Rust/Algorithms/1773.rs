impl Solution {
    pub fn count_matches(
        items: Vec<Vec<String>>,
        rule_key: String,
        rule_value: String,
    ) -> i32 {
        let index = match rule_key.as_str() {
            "color" => 1,
            "name" => 2,
            _ => 0,
        };
        items.iter().filter(|i| i[index] == rule_value).count() as i32
    }
}
