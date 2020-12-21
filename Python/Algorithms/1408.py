class Solution:
    def stringMatching(self, words):
        len_ = len
        words.sort(key=len_)
        res, length = [], len_(words)

        for idx, w in enumerate(words, start=1):
            # start from next element.
            for k in range(idx, length):
                w2 = words[k]
                # might have equal length words, don't cmp.
                if len_(w) == len_(w2):
                    continue
                if w in w2:
                    res.append(w)
                    break
        return res
