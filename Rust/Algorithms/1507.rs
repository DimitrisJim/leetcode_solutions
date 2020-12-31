use std::collections::HashMap;

impl Solution {
    pub fn reformat_date(date: String) -> String {
        let months = [
            "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep",
            "Oct", "Nov", "Dec",
        ];
        let mut date: Vec<_> =
            date.split(' ').rev().map(|x| x.to_string()).collect();
        date[2] =
            date[2].trim_end_matches(char::is_alphabetic).to_string();
        if date[2].len() == 1 {
            date[2].insert(0, '0');
        };
        date[1] = (months.iter().position(|x| *x == date[1]).unwrap() + 1)
            .to_string();
        if date[1].len() == 1 {
            date[1].insert(0, '0');
        }
        date.join("-")
    }
}
