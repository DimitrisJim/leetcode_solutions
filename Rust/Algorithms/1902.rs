impl Solution {
    pub fn largest_odd_number(mut num: String) -> String {
        let set = [0, 1, 0, 1, 0, 1, 0, 1, 0, 1];
        for c in num.clone().as_bytes().iter().rev() {
            if set[(c - 48) as usize] == 1 {
                break;
            }
            num.pop();
        }
        return num;
    }
}
