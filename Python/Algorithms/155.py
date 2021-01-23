class MinStack:

    def __init__(self):
        """
        self.min holds the current min among all values.
        self.st acts as our stack.
        """
        self.min, self.st = None, []

    def push(self, x):
        """ Update min as values are pushed. Must handle special case
        self.min is None which occurs on first push or on first push after
        stack has been emptied.

        Amortized O(1) due to append.
        """
        self.st.append(x)
        if self.min is None:
            self.min = x
        else:
            if x <= self.min:
                self.min = x

    def pop(self):
        """ Pop from underlying list. If min is the value being pop'ed, we
        have to go through the values and find the next min.

        If this is last pop (and self.st becomes empty) reset to None.
        O(N) due to call to min.
        """
        st = self.st
        x = st.pop()
        if x == self.min:
            self.min = min(st) if st else None

    def top(self):
        """ Straight-forward. O(1) - indexing. """
        return self.st[-1]

    def getMin(self):
        """ Straight-forward. O(1) - attribute access."""
        return self.min
