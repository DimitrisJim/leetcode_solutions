class Solution:
    def mostVisited(self, n, rounds):
        length, i = len(rounds), 0
        begin = (0, 0)
        # If rounds[0] isn't 1, we start from some position
        # after sector 1, continue along until we go past the 
        # last sector (or return early if we don't.)
        if rounds[i] != 1:
            start = rounds[0]
            while i < length - 1 and rounds[i] < rounds[i+1]:
                i = i + 1
            # return early if we reached the end
            if i == length - 1:
                return [i for i in range(start, rounds[-1] + 1)]
            # we've haven't reached end, keep track of all extra
            # sectors until n.
            begin = (start, n)

        # similar to begin only from end.
        trail = (1, rounds[-1]) if rounds[-1] != n else (0, 0)

        # fill up with (extra) times we passed through
        # sector.
        res = [0] * n
        for (s, e) in (begin, trail):
            if s and e:
                for i in range(s, e + 1):
                    res[i-1] += 1

        # find max'es and return.
        m = max(res)
        return [i + 1 for i, j in enumerate(res) if j == m]
