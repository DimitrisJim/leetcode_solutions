class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        # reset to start by sorting.
        nums.sort()
        perms, length = [], len(nums) - 1
        while True:
            perms.append(nums[::])
            i = length
            # find shortest non-decreasing suffix of nums
            while i > 0:
                if nums[i - 1] < nums[i]:
                    break
                i -= 1
            k = 0
            if i > 0:
                j = length
                while j >= i:
                    if nums[j] > nums[i - 1]:
                        break
                    j -= 1
                # nums[j] is the smallest element in nums[i:] that is greater
                # than nums[i - 1], switch and reverse nums[i+1:]
                nums[i - 1], nums[j] = nums[j], nums[i - 1]
                k = i
            else:
                break
            nums[k:] = nums[-1:k-1:-1]
        return perms
