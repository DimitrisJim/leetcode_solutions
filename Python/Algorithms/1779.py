class Solution:
    def nearestValidPoint(self, x: int, y: int, points) -> int:
        # not a good idea to iniatilze prev_min this way.
        prev_min, index = 10 << 10, -1
        abs_ = abs
        for i, (xi, yi) in enumerate(points):
            if xi == x:
                dst = y - yi
            elif yi == y:
                dst = x - xi
            else:
                continue
            dst = abs_(dst)
            if dst < prev_min:
                prev_min, index = dst, i
        return index