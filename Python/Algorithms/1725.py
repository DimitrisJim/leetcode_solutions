class Solution:

    def countGoodRectangles(self, rectangles):
        max_value = count = 0
        for i, j in rectangles:
            m = i if i < j else j
            if m == max_value:
                count = count + 1
            elif m > max_value:
                count = 1
                max_value = m
        return count
