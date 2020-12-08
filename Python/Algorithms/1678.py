class Solution:
    def interpret(self, s: str) -> str:
        result, length, i = [], len(s), 0
        while i < length:
            # () case
            if s[i] == '(' and s[i+1] == ')':
                result.append('o')
                i = i + 2
            elif s[i] == 'G':
                result.append('G')
                i = i + 1
            # case (al)
            else:
                result.append('al')
                i = i + 4
        return "".join(result)
