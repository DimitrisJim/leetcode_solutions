class Solution:
    def findOcurrences(self, text, first, second):
        words, result = text.split(), []
        start, limit = 0, len(words) - 2

        # limit is len(words) - 3 because, in the best case
        # we look at triplets.
        while start < limit:
            if words[start] == first:
                if words[start+1] == second:
                    result.append(words[start+2])
                    # skip over two (note that
                    # third word might be next first.)
                    start = start + 2
                    continue
                # skip one, try second as first.
                start = start + 1
                continue
            # skip first invalid word
            start = start + 1
        return result
