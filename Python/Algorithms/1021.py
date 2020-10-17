class Solution:
    def removeOuterParentheses(self, S):
        if S == "" or S == "()":
            return ""
        if S == "(())":
            return "()"
        res = []
        append = res.append
        depth = 0  # how many '(' have we seen?
        for s in S:
            if s == '(':
                if depth:
                    append(s)
                depth = depth + 1
            else:
                depth = depth - 1
                if depth:
                    append(s)
        return "".join(res)
