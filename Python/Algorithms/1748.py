class Solution:
    def sumOfUnique(self, nums: List[int]) -> int:
        """ Uniques holds final unique values. Seen
        helps us filter values already seen. """
        seen, uniques = set(), set()
        for i in nums:
            if i in seen:
                # remove if in seen *and* in uniques.
                if i in uniques:
                    uniques.remove(i)
            else:
                uniques.add(i)
                seen.add(i)
        return sum(uniques)
