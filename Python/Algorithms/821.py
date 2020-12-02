from itertools import chain


class Solution:
    def shortestToChar(self, S, C):
        # build a list of ranges
        ranges, prev_pos, rng = [], -1, range
        while (pos := S.find(C, prev_pos+1)) != -1:
            # first search we do, add range until (including) 0.
            if prev_pos == - 1:
                ranges.append(rng(pos, -1, -1))
            else:
                # need to add increasing/decreasing sequence:
                # get middle point.
                diff = pos - prev_pos
                middle = diff // 2
                # start from 1. (we've already included 0) going up.
                ranges.append(rng(1, middle + (1 if diff % 2 else 0)))
                # going down.
                ranges.append(rng(middle, -1, -1))
            # update previous position.
            prev_pos = pos

        # Add remaining distances if we haven't reached the end.
        if prev_pos != len(S) - 1:
            diff = len(S) - prev_pos
            ranges.append(rng(1, diff))
        # return chained ranges.
        return chain.from_iterable(ranges)
