impl Solution {
    pub fn gcd_of_strings(str1: String, str2: String) -> String {
        let (str1, str2) = (str1.as_str(), str2.as_str());
        let (mut l, mut s) = if str1.len() > str2.len() { (str1, str2) } else { (str2, str1) };
        
        while s.len() > 0 && l.starts_with(s) {
            while l.starts_with(s) {
                l = &l[s.len()..];
            }
            let tmp = s;
            s = l;
            l = tmp;
        }
        if s.len() == 0 {
            l.to_owned()
        } else {
            String::new()
        }
    }
}