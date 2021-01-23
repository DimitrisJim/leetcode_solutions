from collections import deque


class MyStack:

    def __init__(self):
        """ Initialize your data structure here. """
        self.d = deque()

    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        self.d.append(x)

    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        # basically rotate
        d = self.d
        l = len(d) - 1
        while l:
            d.append(d.popleft())
            l = l - 1
        return d.popleft()

    def top(self) -> int:
        """
        Get the top element.
        """
        # basically rotate
        d = self.d
        l = len(d) - 1
        while l:
            d.append(d.popleft())
            l = l - 1
        x = d[0]
        d.append(d.popleft())
        return x

    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        return len(self.d) == 0
