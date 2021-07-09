""" A minimal UF implementation. """

class UnionFind:
    """ Typical DSU implementation with path-compression and
    union by rank.
    
    Requires members to be able to be used as indexes.
    """

    def __init__(self, iterable=None):
        self.parent = list(iterable or [])
        self.rank = [0] * len(self.parent)

    def find(self, element):
        p = self.parent
        if element == p[element]:
            return element
        # compress path
        p[element] = self.find(p[element])
        return p[element]

    def union(self, a, b):
        """ Uses union by rank. """
        rank = self.rank
        a = self.find(a)
        b = self.find(b)
        if a != b:
            if rank[a] < rank[b]:
                a, b = b, a
            self.parent[b] = a
            if rank[a] == rank[b]:
                rank[a] += 1
