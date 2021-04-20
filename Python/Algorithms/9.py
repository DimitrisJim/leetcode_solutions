class Solution:
    def removeElement(self, nums, val: int) -> int:
        start, finish = 0, len(nums)
        while start < finish:
            # replace with last element of list
            if nums[start] == val:
                end = nums.pop()
                finish -= 1
                if start < finish:
                    nums[start] = end
            else:
                start += 1
        return finish
