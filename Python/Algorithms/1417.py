from string import digits


class Solution:
    def reformat(self, s):
        d = {*digits}
        nums, chars = [], []
        for ch in s:
            if ch in d:
                nums.append(ch)
            else:
                chars.append(ch)

        # Counted chars, return a permutation.
        diff = len(nums) - len(chars)
        arr = []
        # same size
        if diff == 0:
            z = zip(nums, chars)
        # nums is larger.
        elif diff == 1:
            arr.append(nums.pop())
            z = zip(chars, nums)
        # chars is larger.
        elif diff == -1:
            arr.append(chars.pop())
            z = zip(nums, chars)
        # if sizes differ by more than one, can't
        # reformat string.
        else:
            return ""
        for i, j in z:
            arr.append(i)
            arr.append(j)
        return "".join(arr)
