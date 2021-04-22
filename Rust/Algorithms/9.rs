impl Solution {
    pub fn is_palindrome(x: i32) -> bool {
        if x < 0 {
            return false;
        }
        
        let v: Vec<_> = x.to_string().chars().collect();
        let (mut i, mut j) = (0, v.len() - 1);
        while i < j {
            if v[i] != v[j] {
                return false;
            }
            i += 1;
            j -= 1;
        }
        true
    }
}