from heapq import heapify, heappush, heappop

class Solution:
    def lastStoneWeight(self, stones):
        push, pop = heappush, heappop
        stones = [-i for i in stones]
        heapify(stones)
        while len(stones) > 2:
            diff = -pop(stones) - -pop(stones)
            if diff:
                push(stones, -diff)
        if len(stones) == 1:
            return -stones[0]
        return -stones[0] - -stones[1]
