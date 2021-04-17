class Solution:
    charMap = {k: v for k, v in enumerate("0123456789abcdef")}

    def toHex(self, num: int) -> str:
        if not num:
            return "0"
        chars, cm = [], self.charMap
        size = 9
        while num and (size := size - 1):
            # 15 -> 1111
            chars.append(cm[num & 15])
            num >>= 4
        return "".join(reversed(chars))
