class Solution:
    def preorder(self, root: 'Node') -> List[int]:
        # hold current list of nodes (stack)
        # keep track of seen nodes (seen)
        if not root:
            return []
        
        stack, res = [root], []
        while stack:
            # peek, basically.
            node = stack.pop()
            if node.children:
                stack.extend(node.children[::-1])
            res.append(node.val)
        return res      
