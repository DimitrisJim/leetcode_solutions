class MyHashSet:
    """ Use simple separate chaining. """

    # Use primes for size, sizable intervals.
    psizes = [23, 101, 311, 619, 1249, 2251, 6287, 10639]

    class _Bucket:
        __slots__ = 'value', 'next'

        def __init__(self, value, next_=None):
            self.value = value
            self.next = next_

    def __init__(self, size=0, hasher=hash):
        """ Initialize your data structure here. """
        # Separate chaining doesn't really care about
        # load factor afaik.
        self.load_factor = 0.98
        # Use Python built in hash as hasher.
        self.hash = hasher
        self.size = size if size else self.psizes[0]
        self.length = 0

        # initialize, use least required size initially.
        self._storage = [None for _ in range(self.size)]

    def add(self, key: int) -> None:
        index = self.hash(key) % self.size
        # Is there a bucket here?
        if self._storage[index]:
            b = self._storage[index]
            # go to end of linked structure
            if b.value == key:
                return
            while b.next:
                # don't add key if already here.
                if b.value == key:
                    return
                b = b.next
            b.next = self._Bucket(key)
        # No bucket here, add one.
        else:
            self._storage[index] = self._Bucket(key)
        self.length += 1

        # Resize if we surpass load factor.
        if (self.length / self.size) > self.load_factor:
            self._resize_storage()

    def remove(self, key: int):
        index = self.hash(key) % self.size
        # go through bucket and look for entry with value == key
        b = self._storage[index]
        if not b:
            return
        # head of linked structure contains key
        if b.value == key:
            self._storage[index] = b.next
			self.length -= 1
        # key is somewhere in linked structure
        else:
            while b.next:
                if b.next.value == key:
                    # replace next pointer, decrease length
                    b.next = b.next.next
                    self.length -= 1
                    break
                b = b.next

    def contains(self, key: int) -> bool:
        """
        Returns true if this set contains the specified element
        """
        # go through bucket and look for entry with value == key
        index = self.hash(key) % self.size
        b = self._storage[index]
        if not b:
            return False
        while b:
            if b.value == key:
                return True
            b = b.next
        return False

    def _resize_storage(self):
        """ Resize to next size in primes. """
        # find next size to use
        size, i, psizes = self.size, 0, self.psizes
        while size >= psizes[i]:
            i = i + 1
        size = psizes[i]

        # add everything again.
        _ = MyHashSet(size)
        add = _.add
        for b in self._storage:
            while b:
                add(b.value)
                b = b.next

        # Update
        self._storage = _._storage
        self.size = size
        self.length = _.length


###################################################################

class MyHashSet:
    """ Open addressing for conflict resolution. """

    # Dummy slot used for deletion.
    class _dummy:
        pass

    # Use primes for size, sizable intervals.
    psizes = [23, 101, 311, 619, 1249, 2251, 6287, 10639]
    excludes = {None, _dummy}
    load_factor = .7

    @staticmethod
    def probe_linear(k, size, hasher=hash):
        """ Linear probing."""
        i = 0
        while True:
            yield int(hasher(k) + i) % size
            i = i + 1

    @staticmethod
    def probe_quadratic(k, size, hasher=hash):
        """ Quadratic probing. Yields positions. """
        c, i = 1/2, 0
        while True:
            yield int(hasher(k) + 1/2 * i + 1/2 * (i ** 2)) % size
            i = i + 1

    def __init__(self, size=0, probe=None):
        """ Initialize your data structure here. """
        self.prober = probe if probe else self.probe_linear
        self.length = 0
        self._storage = [None for _ in range(size if size else self.psizes[0])]

    def add(self, key: int) -> None:
        """ Add to the set. If value already exists do nothing. """
        size = len(self._storage)
        excludes = self.excludes
        for slot in self.prober(key, size):
            value = self._storage[slot]
            # if it's here, do nothing.
            if value == key:
                return

            # If we find a dummy or a None, add it.
            if value in excludes:
                self._storage[slot] = key
                self.length += 1
                if (self.length / size) >= self.load_factor:
                    self._resize_storage()
                return

    def remove(self, key: int):
        """ Removal. Using lazy deletion whereby a dummy value fills
        the slot of the value removed.
        """
        for slot in self.prober(key, len(self._storage)):
            value = self._storage[slot]
            # found slot, empty, not here.
            if value is None:
                return

            # Replace with a dummy value.
            if value == key:
                self._storage[slot] = self._dummy
                self.length -= 1
                return

    def contains(self, key: int) -> bool:
        """ Membership testing. """
        dummypos = -1
        for slot in self.prober(key, len(self._storage)):
            # found empty position, set.
            value = self._storage[slot]
            if value is None:
                return False
            if value is self._dummy:
                dummypos = slot

            # found
            if value == key:
                # if we've found a dummypos, swap.
                if dummypos != -1:
                    self._storage[dummypos] = self._storage[slot]
                    self._storage[slot] = None
                return True
        # unreachable
        return False

    def _resize_storage(self):
        """ Resize to next largest size in primes. """
        # find next size to use
        size, i, sizes = len(self._storage), 0, self.psizes
        while size >= sizes[i]:
            i = i + 1
        size = sizes[i]

        # rehash everything and add it again.
        # meh, need to pass probe type again.
        tmpS = MyHashSet(size, self.prober)
        excludes, add = self.excludes, tmpS.add
        for i in self._storage:
            if i not in excludes:
                add(i)

        # Update
        self._storage = tmpS._storage
        self.length = tmpS.length
