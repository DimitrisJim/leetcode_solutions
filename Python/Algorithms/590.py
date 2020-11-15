class Solution:
    def postorder(self, root: 'Node') -> List[int]:
        # hold current list of nodes (stack)
        # keep track of seen nodes (seen)
        if not root:
            return []
        
        stack, seen, res = [root], set(), []
        while stack:
            # peek, basically.
            node = stack[-1]
            # if we've seen it before, we are walking up from a 
            # subtree. We need to remove it from the stack and 
            # add it to the result.
            if node in seen:
                res.append(stack.pop().val)
            # first time seeing node, add it to seen.
            else:
                seen.add(node)
                # i.e not a leaf: add children.
                # need to add in reverse order so we first go down
                # leftmost subtree.
                if node.children:
                    stack.extend(reversed(node.children))
                # leaf: remove from stack and add to result.
                else:
                    res.append(stack.pop().val)
        return res
