class Solution:
    def findPoisonedDuration(self, timeSeries, duration):
        if duration == 0:
            return 0
        if duration == 1:
            return len(set(timeSeries))

        seconds = 0
        for i in range(1, len(timeSeries)):
            a1, a2 = timeSeries[i-1], timeSeries[i]
            if a1 != a2:
                seconds += (a2 - a1) if a2 < (a1 + duration) else duration

        # add duration for final element.
        return seconds + duration
