class MyQueue:

    def __init__(self):
        """ Uses two stacks to implement a Queue. Storage holds elements
        pushed right before the first pop.
        """
        self.storage, self.tmp = [], []


    def push(self, x: int) -> None:
        """ Unconditionally add to storage. Equivalent to stack.push."""
        self.storage.append(x)


    def pop(self) -> int:
        """ If tmp is empty, fill it up with all elements from storage, the
        next N pops (where N is the total number of elements in storage before
        filling tmp), will be O(1).
        We only do this operation when tmp is empty. Uses append, pop which are
        the Stacks equivalent of push, pop.
        """
        tmp = self.tmp
        if not tmp:
            # could move in separate helper func
            storage = self.storage
            while storage:
                tmp.append(storage.pop())
        return tmp.pop()

    def peek(self) -> int:
        """
        Get the front element.
        Uses list indexing with [-1] which is equivalent to stack.peek
        """
        tmp = self.tmp
        if not tmp:
            # could move in separate helper func
            storage = self.storage
            while storage:
                tmp.append(storage.pop())
        return tmp[-1]

    def empty(self) -> bool:
        """
        Uses len(lst) == 0 which is equivalent to stack.is_empty
        """
        return len(self.tmp) == len(self.storage) == 0
