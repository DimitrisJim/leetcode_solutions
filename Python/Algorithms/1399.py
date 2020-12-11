from collections import Counter


class Solution:
    def countLargestGroup(self, n):
        # Create counter of digit-sums. (shorthands are kinda too much)
        r, fm, fi, fr = range(1, n+1), map, int, repr
        maxes = Counter(sum(fm(fi, d)) for d in fm(fr, r))
        
        # Count how many digit sums we have.
        count, group = 0, 0
        for k, v in maxes.most_common():
            if group:
                if v != group:
                    return count
                count = count + 1
            else:
                group, count = v, 1
        return count
