impl Solution {
    pub fn freq_alphabets(s: String) -> String {
        let mut v = Vec::from(s);
        let (mut i, mut j, len) = (0, 0, v.len() as usize);
        // Intentionally skip last two chars (handle them separately.)
        while i < (len - 2){
            match v[i+2] {
                // Transform [char][char]# to [char]
                // Note: 35 is code point for '#'
                35 => {
                    let val = v[i+1];
                    match v[i] {
                        // Leading 1 (i.e 11# => 'k')
                        49 => v[j] = val + 58,
                        // Leading 2 (i.e 24# => 'z')
                        _  => v[j] = val + 68,
                    }
                    j += 1;
                    i += 3;
                },
                // Transform single [char] to [char]
                _ => {
                    v[j] = v[i] + 48;
                    j += 1;
                    i += 1;
                }
            }
        }
        // Handle the possible last two [char][char] values. 
        match len - i {
            2 => {
                v[j] = v[i] + 48;
                j += 1;
                v[j] = v[i+1] + 48;
                j += 1;
            },
            1 => {
                v[j] = v[i] + 48;
                j += 1;
            },
            _ => (),
        }
        // Truncate to needed size and return as String
        v.truncate(j);
        String::from_utf8(v).unwrap()
    }
}
