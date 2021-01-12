class Solution:
    def totalMoney(self, n: int) -> int:
        weeks, days = divmod(n, 7)
        partial, week_sum = 0, 28
        for i in range(weeks):
            partial = partial + week_sum
            week_sum = week_sum + 7
        return partial + sum(weeks + i for i in range(1, days + 1))
