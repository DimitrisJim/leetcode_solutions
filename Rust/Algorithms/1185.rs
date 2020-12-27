impl Solution {
    const days_until_month: [i32; 12] =
        [0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334];

    // Return 1 if year is leap year, else 0.
    // See: https://en.wikipedia.org/wiki/Leap_year
    fn is_leap_year(year: i32) -> bool {
        year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)
    }

    // dby => days before year.
    // Return the days until January 1st of this year.
    // Need to add leap days (year / 4) and remove non-leap
    // days (year / 100) but count those / 100 and / 400.
    fn dby(mut year: i32) -> i32 {
        year -= 1;
        year * 365 + year / 4 - year / 100 + year / 400
    }

    // dbm => days before month.
    // Add necesary leap day if year is leap.
    fn dbm(year: i32, month: i32) -> i32 {
        let leap = match month > 2 && Solution::is_leap_year(year) {
            true => 1,
            false => 0,
        };
        Solution::days_until_month[(month - 1) as usize] + leap
    }

    pub fn day_of_the_week(day: i32, month: i32, year: i32) -> String {
        let days = [
            "Sunday",
            "Monday",
            "Tuesday",
            "Wednesday",
            "Thursday",
            "Friday",
            "Saturday",
        ];
        String::from(
            days[((Solution::dby(year) + Solution::dbm(year, month) + day)
                % 7) as usize],
        )
    }
}
