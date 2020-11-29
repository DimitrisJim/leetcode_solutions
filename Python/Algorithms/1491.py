from itertools import islice

class Solution:
    def average(self, salary):
        salary.sort()
        return sum(salary[1:-1]) / (len(salary) - 2)

    # can use islice to maybe help with mem.
    def average_2(self, salary):
        nlen = len(salary) - 2
        salary.sort()
        return sum(islice(salary, 1, nlen+1)) / nlen
