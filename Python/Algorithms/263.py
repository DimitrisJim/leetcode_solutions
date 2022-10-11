class Solution:
    def isUgly(self, n: int) -> bool:
        if n == 0:
            return False
        primes = [2, 3, 5]
        i = 0
        while n != 1:
            prime = primes[i]
            d, r = divmod(n, prime)
            if r == 0:
                n = d
            else:
                i += 1
                
            if i >= 3:
                return False
        return True