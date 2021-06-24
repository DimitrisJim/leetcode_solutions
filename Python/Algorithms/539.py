class Solution:
    def findMinDifference(self, timePoints: List[str]) -> int:
        # Can use a set to hold values. This way we can bail early
        # if we encounter a duplicate.
        timepoints = set()
        for d in timePoints:
            h, m = map(int, d.split(":"))
            v = (h or (0 if m else 24)) * 60 + m
            if v in timepoints:
                return 0
            timepoints.add(v)
        timepoints = sorted(timepoints)
        min_, min_diff = min, 2400
        for i in range(len(timepoints) - 1):
            min_diff = min_(min_diff, timepoints[i+1] - timepoints[i])

        # check min time + 1440 (24 * 60) - max_time to see if we have a smaller
        # value on the edges.
        min_diff = min_(min_diff, timepoints[0] + 1440 - timepoints[-1])
        return min_diff
