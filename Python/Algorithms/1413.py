class Solution:
    def minStartValue(self, nums):
        # start with 1, the minimu pos value.
        minimum, currently = 1, 1
        for i in nums:
            # we go through nums and..
            diff = 1 - (currently + i)
            # .. if at any point we fall between 0
            if diff > 0:
                # we must change our minimum to a new
                # minimum and adjust our current value.
                minimum = minimum + diff
                currently = currently + diff
            currently = currently + i
        return minimum
