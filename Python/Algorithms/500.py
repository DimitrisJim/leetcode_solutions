class Solution:
    krows = ["QWERTYUIOP", "ASDFGHJKL", "ZXCVBNM"]

    @classmethod
    def make_rows(cls):
        """
        Create set of frozen sets of characters on each row
        """
        rows = set()
        for k in cls.krows:
            els = "".join([k, k.lower()])
            rows.add(frozenset(els))
        return rows

    def findWords(self, words):
        """Compare set of elements of word with rows."""
        rows, res = self.make_rows(), []
        for w in words:
            wset = {*w}
            if any(wset.issubset(r) for r in rows):
                res.append(w)
        return res
