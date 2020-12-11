class Solution:
    def numberOfLines(self, widths, s):
        widths = {i:j for i, j in zip(ascii_lowercase, widths)}
        lines = line = 0
        for i in s:
            line = line + widths[i]
            if line > 100:
                lines += 1
                line = widths[i]
        return [lines + 1 if line else 0, line]
