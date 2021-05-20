from collections import Counter


class Solution:
    def maximumPopulation(self, logs):
        c = Counter()
        for l in logs:
            c.update(range(l[0], l[1]))

        counts = c.most_common()
        year, value = counts[0]
        for y, v in counts:
            if v != value:
                break
            elif y < year:
                year = y
        return year
