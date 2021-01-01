class Solution:
    def numSmallerByFrequency(self, queries, words):
        # Keep a cache around
        # {f(queries[i]): # words such that f(queries[i]) < f(W)}
        cache, lq, lw = {}, len(queries), len(words)

        def frequency(s):
            """ Count number of occurences of smallest char. """
            l, count = sorted(s), 1
            for i in range(1, len(l)):
                if l[i-1] != l[i]:
                    return count
                count = count + 1
            return count

        # Transform into frequencies and sort.
        words = sorted(map(frequency, words))
        for i in range(lq):
            val = frequency(queries[i])
            # first check cache, on miss -> fill.
            if val not in cache:
                for k in range(lw):
                    if val < words[k]:
                        cache[val] = lw - k
                        break
                # All words in words have < count.
                if val not in cache:
                    cache[val] = 0
            # re-use queries list, place value.
            queries[i] = cache[val]
        return queries
