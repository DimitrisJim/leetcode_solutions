impl Solution {
    pub fn balanced_string_split(s: String) -> i32 {
        let mut i = 1;
        let end = s.len();
        let chars = s.as_bytes();

        let mut count = 0;
        let mut cur_char = chars[0];
        let mut track = 1;
        while i < end {
            let next_char = chars[i];
            if next_char != cur_char {
                track -= 1;
                if track == 0 {
                    count += 1;
                    i += 1;
                    if i < end {
                        cur_char = chars[i];
                        track = 1;
                    }
                    else {
                        break;
                    }
                }
            } 
            else {
                track += 1;
            }
            i += 1;
        }
        count
    }
}