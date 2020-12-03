class Solution:
    def maxDepth(self, root):
        if not root:
            return 0
        
        max_depth = 0
        tracker = [(root, max_depth)]
        while tracker:
            node, depth = tracker.pop()
            if depth > max_depth:
                max_depth = depth
            
            left, right = node.left, node.right
            if left:
                tracker.append((left, depth + 1))
            if right:
                tracker.append((right, depth + 1))
        return max_depth + 1
