impl Solution {
    pub fn convert_to_base7(num: i32) -> String {
        if num == 0 {
            return String::from("0");
        }
        
        let neg = if num > 0 { false } else { true };
        let mut num = if num > 0 { num } else { -num };
        
        let mut result = vec![];
        while num > 0 {
            result.push((num % 7).to_string());
            num /= 7;
        }
        if neg {
            result.push("-".to_string());
        }
        result.into_iter().rev().collect::<Vec<_>>().join("")
    }
}