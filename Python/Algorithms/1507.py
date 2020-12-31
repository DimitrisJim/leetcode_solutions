class Solution:
    months = [
        "Jan", "Feb", "Mar", "Apr",
        "May", "Jun", "Jul", "Aug",
        "Sep", "Oct", "Nov", "Dec"
    ]

    def reformatDate(self, date: str) -> str:
        day, month, year = date.split(' ')
        day, month = day[:-2], self.months.index(month) + 1
        return "-".join([
            year,
            f'0{month}' if month < 10 else f'{month}',
            day if len(day) == 2 else f'0{day}'
        ])
