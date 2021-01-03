from itertools import combinations


class Solution:
    # Shoelace formula, see:
    # https://en.wikipedia.org/wiki/Shoelace_formula#Proof_for_a_triangle
    def largestTriangleArea(self, points):
        a = abs
        return max(
            0.5 * a(x1 * y2 + x2 * y3 + x3 * y1 - x2 * y1 - x3 * y2 - x1 * y3)
            for ((x1, y1), (x2, y2), (x3, y3)) in combinations(points, 3)
        )
