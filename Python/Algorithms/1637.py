class Solution:
    def maxWidthOfVerticalArea(self, points):
        # remove points with same x value
        same_x, r_points = set(), []
        for [x, _] in points:
            if x not in same_x:
                r_points.append(x)
                same_x.add(x)

        length = len(r_points)
        # all on same x.
        if length <= 1:
            return 0
        # else, sort them (ascending) and find max diff.
        r_points.sort()
        return max(r_points[i] - r_points[i-1] for i in range(1, length))
