class Solution:
    def hasCycle(self, head) -> bool:
        if head is None or head.next is None:
            return False
        step, run = head, head.next.next
        while step and run:
            if step == run:
                return True
            step = step.next
            if run.next:
                run = run.next.next
            else:
                return False
        return False
