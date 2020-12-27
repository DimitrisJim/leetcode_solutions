from datetime import date


class Solution:
    def dayOfTheWeek(self, day, month, year):
        # cheat?
        return [
            'Monday', 'Tuesday', 'Wednesday', 'Thursday',
            'Friday', 'Saturday', 'Sunday'
        ][date(year, month, day).weekday()]
