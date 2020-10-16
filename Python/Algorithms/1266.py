class Solution:
    def minTimeToVisitAllPoints(self, points):
        steps = 0
        abs_ = abs
        for i in range(len(points) - 1):
            sourcex, sourcey = points[i]
            destx, desty = points[i+1]
            # move diagonally as much as possible.
            if sourcex != destx or sourcey != desty:
                diffx, diffy = destx - sourcex, desty - sourcey
                absdx, absdy = abs_(diffx), abs_(diffy)
                if absdx < absdy:
                    sourcex = sourcex + diffx
                    sourcey = sourcey + (absdx if diffy > 0 else -absdx)
                    steps = steps + absdx
                else:
                    sourcey = sourcey + diffy
                    sourcex = sourcex + (absdy if diffx > 0 else -absdy)
                    steps = steps + absdy
            # align y1 with y2 by moving vertically.
            if sourcey != desty and sourcex == destx:
                diff = desty - sourcey
                sourcey = sourcey + diff
                steps = steps + abs_(diff)
            # align x1 with x2 by moving horizontically.
            else:
                diff = destx - sourcex
                sourcex = sourcex + diff
                steps = steps + abs_(diff)      
        return steps
