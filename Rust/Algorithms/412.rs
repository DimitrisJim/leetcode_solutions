impl Solution {
    pub fn fizz_buzz(n: i32) -> Vec<String> {
        let mut res = Vec::new();
        let (f, b, fb) = (
            String::from("Fizz"),
            String::from("Buzz"),
            String::from("FizzBuzz"),
        );

        for i in 1..(n + 1) as usize {
            let (r, m) = (i / 3, i % 3);
            if m == 0 {
                res.push(if r % 5 == 0 { fb.clone() } else { f.clone() });
                continue;
            }
            res.push(if i % 5 == 0 { b.clone() } else { i.to_string() });
        }
        res
    }
}
