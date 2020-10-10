class Solution:
    def subtractProductAndSum(self, n: int) -> int:
        s = 0
        p = 1
        while n:
            # extract digits; divmod better than 
            # explicit // and %, C implemented.
            n, d = divmod(n, 10)
            s += d
            p *= d
            
        return p - s
