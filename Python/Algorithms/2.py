# Definition for singly-linked list.
class ListNode:
     def __init__(self, val=0, next=None):
         self.val = val
         self.next = next
         

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        carry = 0
        start, prev = l1, None
        # both lists haven't been exhausted
        while l1 and l2:
            carry, digit = divmod(l1.val + l2.val + carry, 10)
            l1.val = digit
            prev = l1
            l1, l2 = l1.next, l2.next

        # continue with the rest, keep reference to previous valid
        # node in order to add carry if it exists.
        final = None
        if l1:
            while l1:
                carry, digit = divmod(l1.val + carry, 10)
                l1.val = digit
                final = l1
                l1 = l1.next
            if carry:
                final.next = ListNode(1)
        elif l2:
            prev.next = l2
            while l2:
                carry, digit = divmod(l2.val + carry, 10)
                l2.val = digit
                final = l2
                l2 = l2.next
            if carry:
                final.next = ListNode(1)
        else:
            if carry:
                prev.next = ListNode(1)
        return start
