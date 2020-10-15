class Solution:
    def findNumbers(self, nums: List[int]) -> int:
        """
        :type nums: List[int]
        :rtype: int
        """
        evens = 0
        rev = range(10, 100)
        rod = range(100, 1000)
        for i in nums:
            if i in rod:
                continue
            divs = 0
            while True:
                if i < 10:
                    break
                elif i in rev and not (divs & 1):
                    evens += 1
                    break
                i //= 10
                divs += 1
        return evens


# hardcoded approach (leads to faster execution speed.)
def findNumbers(self, nums: List[int]) -> int:
    """
    :type nums: List[int]
    :rtype: int
    """ 
    s = 0
    for _ in nums:
        if 9 < _ < 100 or 999 < _ < 10000 or _ == 100_000:
            s = s + 1
    return s
