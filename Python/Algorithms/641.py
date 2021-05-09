class MyCircularDeque:

    class _node:
        def __init__(self, value, _next=None, _prev=None):
            self.value = value
            self.next = _next
            self.prev = _prev

    def __init__(self, k: int):
        """
        Initialize your data structure here. Set the size of the deque to be k.
        """
        self.size = k
        self.length = 0
        self.head = self.tail = None

    def insertFront(self, value: int) -> bool:
        """
        Adds an item at the front of Deque. Return true if the operation is successful.
        """
        if self.length >= self.size:
            return False

        if self.head:
            old = self.head
            self.head = self._node(value, old)
            old.prev = self.head
        else:
            self.head = self.tail = self._node(value)
        self.length += 1
        return True

    def insertLast(self, value: int) -> bool:
        """
        Adds an item at the rear of Deque. Return true if the operation is successful.
        """
        if self.length >= self.size:
            return False

        if self.tail:
            tmp = self.tail
            self.tail = self._node(value, None, tmp)
            tmp.next = self.tail
        else:
            self.head = self.tail = self._node(value)
        self.length += 1
        return True

    def deleteFront(self) -> bool:
        """
        Deletes an item from the front of Deque. Return true if the operation is successful.
        """
        if not self.length:
            return False

        self.length -= 1
        if self.length == 0:
            self.head = self.tail = None
            return True
        self.head = self.head.next
        self.head.prev = None
        return True

    def deleteLast(self) -> bool:
        """
        Deletes an item from the rear of Deque. Return true if the operation is successful.
        """
        if not self.length:
            return False

        self.length -= 1
        if self.length == 0:
            self.head = self.tail = None
            return True
        self.tail = self.tail.prev
        self.tail.next = None
        return True

    def getFront(self) -> int:
        """
        Get the front item from the deque.
        """
        if self.length == 0:
            return -1
        return self.head.value

    def getRear(self) -> int:
        """
        Get the last item from the deque.
        """
        if self.length == 0:
            return -1
        return self.tail.value

    def isEmpty(self) -> bool:
        """
        Checks whether the circular deque is empty or not.
        """
        return self.length == 0

    def isFull(self) -> bool:
        """
        Checks whether the circular deque is full or not.
        """
        return self.length == self.size
