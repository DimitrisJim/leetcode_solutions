class Solution:
    def containsNearbyDuplicate(self, nums, k: int) -> bool:
        # nums => indices
        indices = {}
        for i, v in enumerate(nums):
            if v in indices:
                # check if diff is <= k, else replace index
                # with most recent seen.
                if i - indices[v] <= k:
                    return True
                indices[v] = i
            else:
                indices[v] = i
        return False
