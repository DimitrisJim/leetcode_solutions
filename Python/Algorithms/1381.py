class CustomStack:
    """ Backed by a list, all operations are straight-forward. """

    def __init__(self, maxSize: int):
        self.storage = []
        self.maxsize = maxSize

    def push(self, x: int) -> None:
        if len(self.storage) < self.maxsize:
            self.storage.append(x)

    def pop(self) -> int:
        if self.storage:
            return self.storage.pop()
        return -1

    def increment(self, k: int, val: int) -> None:
        storage = self.storage
        for i in range(min(k, len(storage))):
            storage[i] += val
