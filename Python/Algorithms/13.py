class Solution:
    rtoi = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
    special_combinations = {'IV', 'IX', 'XL', 'XC', 'CD', 'CM'}
    
    def romanToInt(self, s):
        rtoi, special_combs = self.rtoi, self.special_combinations
        
        n, i, end = 0, 0, len(s) - 1
        while i < end:
            if s[i:i+2] in special_combs:
                n = n - rtoi[s[i]] + rtoi[s[i+1]]
                i = i + 2
                continue
            n = n + rtoi[s[i]]
            i = i + 1
        # handle case where s is odd.
        if i == len(s):
            return n
        return n + rtoi[s[-1]]
