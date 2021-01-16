class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def mergeTwoLists(self, l1, l2):
        if not l1 and not l2:
            return None
        new = ListNode()
        ref = new
        while l1 and l2:
            if l1.val <= l2.val:
                ref.val, l1 = l1.val, l1.next
            else:
                ref.val, l2 = l2.val, l2.next
            ref.next = ListNode()
            ref = ref.next

        rem = l1 if l1 else l2
        while rem:
            ref.val, rem = rem.val, rem.next
            if rem:
                ref.next = ListNode()
                ref = ref.next
        return new
