class Solution:
    # hold vowels in set.
    vowels = {*'aAiIeEuUoO'}
    
    def halvesAreAlike(self, s):
        length = len(s)
        count, mid, vowels = 0, length // 2, self.vowels
        # build count of vowels until (not including) mid.
        for i in range(mid):
            if s[i] in vowels:
                count = count + 1
                
        # reduce counts from mid until length.
        for i in range(mid, length):
            if s[i] in vowels:
                count = count - 1
                # bail early.
                if count < 0:
                    return False
        # count == 0 => same number of vowels in each half.
        return count == 0
