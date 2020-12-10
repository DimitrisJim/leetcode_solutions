class Solution:
    @staticmethod
    def deleteNode(node):
        """ Since we can't replace previous node's next, replace
        node's contents
        """
        node.val, node.next = node.next.val, node.next.next
