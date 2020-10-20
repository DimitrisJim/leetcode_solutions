class Solution:
    def numJewelsInStones(self, J, S):
        count = 0
        J = {*J}
        for c in S:
            # if in, jewl, increase count.
            if c in J:
                count = count + 1
        return count
