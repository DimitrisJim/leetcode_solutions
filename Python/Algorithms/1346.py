class Solution:
    def checkIfExist(self, arr: List[int]) -> bool:
        nums = set()
        for num in arr:
            # check if 2 * M in nums
            if num * 2 in nums:
                return True
            # check if M / 2 is in nums
            half = num / 2
            if half % 1 == 0 and half in nums:
                return True
            nums.add(num)
        return False
