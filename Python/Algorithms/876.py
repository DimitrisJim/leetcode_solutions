# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# 20ms - 98.87 14 - 73.76
class Solution:
    def middleNode(self, head):
        mid, inc = head, False
        while head := head.next:
            if inc := not inc:
                mid = mid.next
        return mid
