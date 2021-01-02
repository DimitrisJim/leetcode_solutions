class Solution:
    def maxLengthBetweenEqualCharacters(self, s):
        d = {}
        for index, c in enumerate(s):
            if c in d:
                lst = d[c]
                if index > lst[-1]:
                    lst[-1] = index
            else:
                d[c] = [index, index]

        # Find the max
        max_diff = -1
        for (min_, max_) in d.values():
            # basically, we have two elements.
            if min_ != max_:
                diff = max_ - min_ - 1
                if diff > max_diff:
                    max_diff = diff
        return max_diff
