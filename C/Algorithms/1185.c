static char *days[] = {"Sunday",   "Monday", "Tuesday", "Wednesday",
                       "Thursday", "Friday", "Saturday"};
// Sum days until the given month.
static int days_until_month[] = {0,   31,  59,  90,  120, 151,
                                 181, 212, 243, 273, 304, 334};

// Return 1 if year is leap year, else 0.
// See: https://en.wikipedia.org/wiki/Leap_year
int is_leap_year(int year) {
  return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}

// dby => days before year.
// Return the days until January 1st of this year.
// Need to add leap days (year / 4) and remove non-leap
// days (year / 100) but count those / 100 and / 400.
int dby(int year) {
  year--;
  return year * 365 + year / 4 - year / 100 + year / 400;
}

// dbm => days before month.
// Add necesary leap day if year is leap.
int dbm(int year, int month) {
  return days_until_month[month - 1] + (month > 2 && is_leap_year(year));
}

char *dayOfTheWeek(int day, int month, int year) {
  return days[(dby(year) + dbm(year, month) + day) % 7];
}
