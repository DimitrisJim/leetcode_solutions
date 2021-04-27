class Solution:
    def convertToBase7(self, num: int) -> str:
        if num == 0:
            return "0"
        num, neg = (num, False) if num > 0 else (-num, True)
        res = []
        while num:
            num, r = divmod(num, 7)
            res.append(r)
        if neg:
            res.append("-")
        return "".join(map(str, reversed(res)))
