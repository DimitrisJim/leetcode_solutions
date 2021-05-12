class Solution:
    def isBoomerang(self, points: List[List[int]]) -> bool:
        def slope(p1, p2):
            [[x1, y1], [x2, y2]] = [p1, p2]
            return (y2 - y1) / ((x2 - x1) or 1)
        a, b, c = points
        if a == b or a == c or b == c:
            return False
        if a[0] == b[0] == c[0] or a[1] == b[1] == c[1]:
            return False
        return not (slope(a, b) == slope(a, c) == slope(b, c))
