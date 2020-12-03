use std::collections::HashSet;

impl Solution {
    pub fn num_unique_emails(mut emails: Vec<String>) -> i32 {
        let mut email_set = HashSet::new();
        for email in emails.iter_mut() {
            let mut partial_result = String::new();
            let mut split_point = 0;
            for (i, ch) in email.chars().enumerate() {
                match ch {
                    '+' => {
                        split_point = email.rfind("@").unwrap();
                        break;
                    }
                    '@' => {
                        split_point = i;
                        break;
                    }
                    '.' => {}
                    _ => {
                        partial_result.push(ch);
                    }
                }
            }
            partial_result.push_str(&email.split_off(split_point));
            email_set.insert(partial_result);
        }
        email_set.len() as i32
    }
}
