# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def getDecimalValue(self, head) -> int:
        sum_, next_ = head.val, head.next
        while next_:
            sum_ <<= 1
            sum_ |= next_.val
            next_ = next_.next
        return sum_


# initial solution that's more explicit:
from itertools import starmap


def getDecimalValue(self, head) -> int:
    bits = []
    add = int.__add__
    append = bits.append
    while True:
        val, next_ = head.val, head.next
        append(add(val, 1) if val else 0)
        if next_ is None:
            break
        head = next_
    pows = range(len(bits) - 1, 0, -1)
    partial_sum = sum(starmap(pow, zip(bits, pows)))
    return add(partial_sum, 1) if bits[-1] else partial_sum
