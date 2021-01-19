"""
See:
    https://en.wikipedia.org/wiki/Pascal%27s_triangle#Calculating_a_row_or_diagonal_by_itself
"""


class Solution:
    def generate(self, numRows):
        res, round_ = [], round
        for n in range(numRows):
            sub = [1]
            # elements are mirrored after mid point,
            # so only calc until there.
            odd = False
            if (n + 1) & 1:
                mid, odd = (n + 1) // 2 + 1, True
            else:
                mid = (n + 1) // 2
            # See url for this part.
            for k in range(1, mid):
                sub.append(round_(sub[-1] * ((n + 1 - k) / k)))

            # extend with mirrored values and add to result.
            sub.extend(reversed(sub[:-1] if odd else sub))
            res.append(sub)
        return res
