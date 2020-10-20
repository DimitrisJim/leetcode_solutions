class Solution:
    def busyStudent(self, startTime, endTime, queryTime):
        count = 0
        for i in range(len(startTime)):
            if startTime[i] <= queryTime:
                if queryTime <= endTime[i]: 
                    count = count + 1
        return count

    def busyStudent2(self, startTime, endTime, queryTime):
        return sum(1 for s, e in zip(startTime, endTime) if s <= queryTime <= e)
