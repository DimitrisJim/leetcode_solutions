class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        # edge case
        if not head:
            return head

        original_head = head
        while next_ := head.next:
            if head.val == next_.val:
                head.next = next_.next
            else:
                head = next_
        return original_head
