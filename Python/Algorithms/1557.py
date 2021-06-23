class Solution:
    def findSmallestSetOfVertices(self, n: int, edges: List[List[int]]) -> List[int]:
        # faster way to find vertices with in degree 0?
        return set(range(n)) - set(map(itemgetter(1), edges))
