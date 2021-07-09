class Solution:
    """ Note: for UnionFind structure, see Structures/UnionFind/uf.py. """
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        # Yes, goes from 0-n+1 but we don't use 0.
        uf = UnionFind(range(len(edges)+1))

        last = None
        for (u, v) in edges:
            if uf.find(u) == uf.find(v):
                last = [u, v]
            else:
                uf.union(u, v)
        return last
