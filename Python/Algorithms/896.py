class Solution:
    def isMonotonic(self, A):
        decreases = None
        for i in range(len(A) - 1):
            a, b = A[i], A[i+1]
            # don't need to look at equal elements.
            if a != b:
                if decreases is None:
                    decreases = (a > b)
                # Carefull, operator precedence!
                elif (a > b) != decreases:
                    return False
        return True
