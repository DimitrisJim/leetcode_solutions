class Solution:
    def moveZeroes(self, nums):
        length = len(nums)
        on_zero = run = 0
        
        while True:
            # find first zero in nums.
            while nums[on_zero]:
                on_zero = on_zero + 1
                if on_zero == length:
                    return
            # stops on first non-zero value of nums
            while not nums[run] or run < on_zero:
                run = run + 1
                if run == length:
                    return
            nums[on_zero], nums[run] = nums[run], nums[on_zero]
