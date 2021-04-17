impl Solution {
    pub fn to_hex(mut n: i32) -> String {
        if n == 0 {
            return String::from("0");
        }
       let map: Vec<char> = "0123456789abcdef".chars().collect(); 
    
        let mut res = Vec::with_capacity(8);
        let mut size = 8;
        while n != 0 && size > 0 {
            res.push(map[(n & 15) as usize]);
            n >>= 4;
            size -= 1;
        }
        
        res.iter().rev().collect::<String>()
    }
}