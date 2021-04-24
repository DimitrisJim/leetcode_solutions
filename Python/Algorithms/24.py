class Solution:
    def swapPairs(self, head):
        if not head or not head.next:
            return head

        # set current, previous and next.
        cur, prev = head, None
        next_ = cur.next
        # keep reference to will-be head.
        head = next_
        # we know it will run at least once, we checked
        # next in the previous if.
        while next_:
            # the old switcharoo.
            cur.next = next_.next
            next_.next = cur
            # make previous point to next.
            if prev:
                prev.next = next_
            # update previous, current, next.
            prev = cur
            cur = cur.next
            if not cur:
                break
            next_ = cur.next
        return head
