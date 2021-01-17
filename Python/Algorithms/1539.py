class Solution:
    def findKthPositive(self, arr: List[int], k: int) -> int:
        start = 1
        for j in arr:
            if start != j:
                step = (j - start)
                if step >= k:
                    # -1 adjusts for previous + 1 added to start.
                    return start + k - 1
                k = k - step
                start = j + 1
            else:
                start = start + 1
        # -1 adjusts for final + 1 added to start.
        return start + k - 1
