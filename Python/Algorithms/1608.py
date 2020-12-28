class Solution:
    def specialArray(self, nums):
        length = len(nums)
        rng = range(length)
        # Start from end. (todo, try starting from beginning)
        for i in range(1, length+1):
            # keep track of matches (>= i)
            match = 0
            for idx in rng:
                n = nums[idx]
                if n >= i:
                    match = match + 1
                    # bail when matches are > i.
                    if match > i:
                        break
                    continue
                # Bail if not enough elements left.
                if match + length - idx < i:
                    break
            # return as soon as we find the match.
            if match == i:
                return i
        return -1
