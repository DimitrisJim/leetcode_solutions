class Solution:
    def reverseList(self, head):
        new_head = tail = None
        while (head):
            tail = new_head
            head, new_head = head.next, head
            new_head.next = tail
        return new_head
