class Solution:
    def minOperations(self, logs):
        # need to keep track if in main, so we
        # ignore move to parent.
        in_main, depth = True, 0
        for log in logs:
            if log == '../':
                if not in_main:
                    depth = depth - 1
                    if depth == 0:
                        in_main = True
            elif log == './':
                continue
            else:
                # we move to a child folder
                depth = depth + 1
                if in_main:
                    in_main = not in_main
        return depth
