impl Solution {
    pub fn check_record(s: String) -> bool {
        let (mut consecutive, mut a_count) = (0, 0);
        for i in s.chars() {
            if i == 'L' {
                consecutive += 1;
                if consecutive == 3 {
                    return false;
                }
                continue;
            }
            if i == 'A' {
                a_count += 1;
                if a_count > 1 {
                    return false;
                }
            }
            consecutive = 0;
        }
        true
    }
}
