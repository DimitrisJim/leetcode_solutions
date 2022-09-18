class Solution:
    def arithmeticTriplets(self, nums: List[int], diff: int) -> int:
        pairs, end = 0, len(nums)
        
        # go through the pairs, break early.
        for i in range(end-2):
            for j in range(i+1, end-1):
                numdiff = nums[j] - nums[i]
                if numdiff > diff:
                    break
                if numdiff == diff:
                    for k in range(j+1, end):
                        numdiff = nums[k] - nums[j]
                        if numdiff > diff:
                            break
                        if numdiff == diff:
                            pairs += 1
        return pairs