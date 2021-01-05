"""
Based on triangle inequality that states that for any triangle, the sum 
of the lengths of any two sides must be greater than or equal to the length 
of the remaining side.

See: https://en.wikipedia.org/wiki/Triangle_inequality#Mathematical_expression_of_the_constraint_on_the_sides_of_a_triangle
"""

class Solution:
    def largestPerimeter(self, A):
        # Go from largest candidates to smallest.
        A.sort(reverse=True)
        for i in range(len(A) - 2):
            # Triangle inequalities.
            a, b, c = A[i], A[i+1], A[i+2]
            if a + b > c and c + a > b and b + c > a:
                return a + b + c
        return 0
