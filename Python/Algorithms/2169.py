class Solution:
    def countOperations(self, num1: int, num2: int) -> int:
        ops = 0
        while num1 > 1 and num2 > 1:
            if num1 > num2:
                num1 -= num2
            else:
                num2 -= num1
            ops += 1
            
        # breaking out of loop we'll either be 0 or 1.
        if num1 == 0 or num2 == 0:
            return ops
        # -1 cancels whichever of num1/num2 == 1.
        return ops + num2 + num1 - 1