class FrontMiddleBackQueue:

    class _Node:
        def __init__(self, value, next_=None, prev=None):
            self.value = value
            self.next = next_
            self.prev = prev

    def __init__(self):
        self.head = self.tail = self.middle = None
        # length is needed to know odd/even num of elements.
        self.length = 0

    # No matter how we push, in all cases, if we go from an even
    # length to an odd length, middle needs to be advanced by one
    # position (to self.middle.next)
    def pushFront(self, val: int) -> None:
        self.length += 1
        # first insertion.
        if not self.head:
            self.head = self.middle = self.tail = self._Node(val)
            return

        # place new head before self.head
        new_head = self._Node(val, self.head)
        self.head.prev = new_head
        self.head = new_head

        # middle changes if length goes from even to odd:
        if self.length & 1:
            self.middle = self.middle.next

    def pushMiddle(self, val: int) -> None:
        self.length += 1
        # first insertion.
        if not self.head:
            self.head = self.middle = self.tail = self._Node(val)
            return

        # special case where we have 1 value and head equals middle.
        if self.head == self.middle:
            self.head.next = self._Node(val, None, self.head)
        else:
            new_middle = self._Node(val, self.middle, self.middle.prev)
            self.middle.prev = new_middle
            self.middle = new_middle

        # if we went from even to odd, advance middle.
        if length & 1:
            self.middle = self.middle.next

    def pushBack(self, val: int) -> None:
        self.length += 1
        # first insertion.
        if not self.head:
            self.head = self.middle = self.tail = self._Node(val)
            return

        prev_tail = self.tail
        new_tail = self._Node(val, None, prev_tail)
        prev_tail.next = new_tail
        self.tail = new_tail

        # middle changes if length goes from even to odd:
        if self.length & 1:
            self.middle = self.middle.next

    def popFront(self) -> int:
        if not self.head:
            return -1

        old_head = self.head
        new_head = old_head.next
        new_head.prev = old_head.prev
        self.head = new_head

        # need to move middle over if we're going from odd to even
        if self.length & 1:
            self.middle = self.middle.next

        self.length -= 1

        old_head.next = old_head.prev = None
        return old_head.value

    def popMiddle(self) -> int:
        if not self.head:
            return -1

        # new middle is always going to be self.middle.next
        old_middle = self.middle
        new_middle = self.middle.next
        new_middle.prev = old_middle.prev
        self.middle = new_middle
        self.length -= 1

        old_middle.next = old_middle.prev = None
        return old_middle.value

    def popBack(self) -> int:
        if not self.head:
            return -1
        # replace self.head.prev with self.head.prev.prev
        old_tail = self.head.prev
        self.head.prev = old_tail.prev
        self.head.prev.next = self.head

        # need to readjust middle if we're going from odd to even
        if self.length & 1:
            self.middle = self.middle.prev
        self.length -= 1

        old_tail.next = old_tail.prev = None
        return old_tail.value
