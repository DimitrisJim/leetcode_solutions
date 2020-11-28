class Solution:
    def removeDuplicates(self, S: str) -> str:
        stack = []
        push, pop = stack.append, stack.pop
        for c in S:
            if stack and stack[-1] == c:
                pop()
            else:
                push(c)
        return "".join(stack)
