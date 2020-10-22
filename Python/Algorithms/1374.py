class Solution:
    
    def yield_chars(self, n):
        yield from repeat('a', n - 2) if n & 1 else repeat('a', n-1)
        yield "bc" if n & 1 else "b"
    
    def generateTheString(self, n: int) -> str:
        if n == 1:
            return 'a'
        return "".join(self.yield_chars(n)) 
