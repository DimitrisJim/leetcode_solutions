class Solution:
    # 14.1 84.41
    def buildArray(self, target, n):
        ops = []
        app, ext = ops.append, ops.extend
        start = 0
        for i in target:
            diff = i - start - 1
            # Add any skipped over elements.
            if diff:
                ext(["Push", "Pop"] * diff)
            # Add the Push for i.
            app("Push")
            start = i
        return ops
