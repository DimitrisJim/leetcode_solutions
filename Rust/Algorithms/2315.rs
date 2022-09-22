impl Solution {
    pub fn count_asterisks(s: String) -> i32 {
        let (mut count, mut flag) = (0, false);
        
        for ch in s.chars() {
            if ch == '|' {
                flag = !flag;
                continue;
            }
            if ch == '*' && !flag {
                count += 1;
            }
        }
        count
    }
}