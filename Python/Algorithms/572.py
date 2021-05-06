class Solution:

    def isSubtree(self, root, subRoot) -> bool:
        # given two roots with matching values, verify subtrees
        # have the same values.
        def nodes_match(node1, node2):
            if node1.val != node2.val:
                return False

            left1, right1 = node1.left, node1.right
            left2, right2 = node2.left, node2.right

            # Recurse into children and combine their results
            # as our overall result.
            result = True
            if left1 and left2:
                result = nodes_match(left1, left2)
            else:
                # True if both None
                result = left1 is None and left2 is None
            if right1 and right2:
                return result and nodes_match(right1, right2)
            # True if both None
            return result and right1 is None and right2 is None

        # Find candidate nodes, i.e, nodes with node.val == subroot.val
        nodes, rootval = [root], subRoot.val
        while nodes:
            node = nodes.pop()
            if node.val == rootval:
                if nodes_match(node, subRoot):
                    return True

            left, right = node.left, node.right
            if left:
                nodes.append(left)
            if right:
                nodes.append(right)
        return False
