impl Solution {
    pub fn reformat(s: String) -> String {
        let (mut chars, mut nums) = (Vec::new(), Vec::new());
        for c in s.chars() {
            match char::is_numeric(c) {
                true => chars.push(c),
                false => nums.push(c),
            }
        }

        let diff = nums.len() as i32 - chars.len() as i32;
        let mut res = Vec::with_capacity(s.len());

        match diff {
            0 | 1 => {
                if diff == 1 {
                    res.push(nums.pop().unwrap());
                }
                // Feel like there's a better way to do this.
                chars.into_iter().for_each(|x| {
                    res.push(x);
                    res.push(nums.pop().unwrap())
                });
            }
            -1 => {
                res.push(chars.pop().unwrap());
                // Feel like there's a better way to do this.
                nums.into_iter().for_each(|x| {
                    res.push(x);
                    res.push(chars.pop().unwrap())
                });
            }
            _ => return String::from(""),
        }
        res.into_iter().collect()
    }
}
