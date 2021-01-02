class Solution:
    def slowestKey(self, releaseTimes, keysPressed):
        max_indices, max_, = [0], releaseTimes[0]
        for i in range(1, len(releaseTimes)):
            m = releaseTimes[i] - releaseTimes[i-1]
            if m > max_:
                max_indices, max_ = [i], m
            elif m == max_:
                max_indices.append(i)
        return max(keysPressed[i] for i in max_indices)
