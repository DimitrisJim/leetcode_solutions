class Solution:
    def kWeakestRows(self, mat, k: int):
        # sort by sum of rows and return row indices as attached by enumerate
        return [i for i, _ in sorted(
            enumerate(mat), key=lambda x: sum(x[1]))[:k]
        ]
