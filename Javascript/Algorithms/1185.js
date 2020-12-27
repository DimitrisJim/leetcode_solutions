// (Ab)Use closure scope.
let dayOfTheWeek = (day, month, year) => {
    
 const days = ["Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"],
       days_until_month = [0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334],
       floor = Math.floor;
    // Return 1 if year is leap year, else 0.
    // See: https://en.wikipedia.org/wiki/Leap_year
    const is_leap_year = () => {
        return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
        },
        // dby => days before year.
        // Return the days until January 1st of this year.
        // Need to add leap days (year / 4) and remove non-leap
        // days (year / 100) but count those / 100 and / 400.
        dby = () => {
            let y = year-1;
            return y * 365 + floor(y / 4) - floor(y / 100) + floor(y / 400);
        },
        // dbm => days before month.
        // Add necesary leap day if year is leap.
        dbm = () => {
            return days_until_month[month-1] + (month > 2 && is_leap_year(year));
        };

    return days[(dby() + dbm() + day) % 7];    
};
