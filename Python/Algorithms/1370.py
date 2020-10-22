from collections import defaultdict


class Solution:
    def sortString(self, s):
        # Keep sorted list of elements,
        sl = sorted(set(s))
        len_ = len
        # edge case, return early.
        if len_(sl) == 1:
            return s

        # keep reversed list of sorted elements.
        revsl = [*reversed(sl)]
        # hold counts for each character.
        counts = defaultdict(int)
        for i in s:
            counts[i] += 1

        # hold chars
        res = []
        append = res.append
        get, pop = counts.get, counts.pop

        # Flags for handling in which direction we loop and when to stop
        toggle, pending = False, True
        while pending:
            for i in sl if not toggle else revsl:
                if i in counts:
                    # if equal to one, final time we see it.
                    # remove it and continue.
                    if get(i) == 1:
                        pop(i)
                        # ok, stop, we can add manually.
                        if len_(counts) == 1:
                            pending = False
                    # it's count is > 1. Decrease it and continue.
                    else:
                        counts[i] -= 1
                    append(i)
            # Toggle direction in which we iterate through characters.
            toggle = not toggle

        # add any left-over character if it exists.
        if len_(counts):
            c, count = counts.popitem()
            res.extend([c for _ in range(count)])

        return "".join(res)
