class Solution:
    def decode(self, encoded, first):
        res = [first]
        push = res.append
        for i in encoded:
            push(i ^ res[-1])
        return res
