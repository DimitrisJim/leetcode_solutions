class Solution:
    def findTarget(self, root, k):
        s, seen = [root], set()
        push, pop = s.append, s.pop
        while s:
            n = pop()
            val, left, right = n.val, n.left, n.right
            if k - val in seen:
                return True
            else:
                seen.add(val)
            if right is not None:
                push(right)
            if left is not None:
                push(left)
        return False
