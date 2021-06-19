class Solution:
    def findCenter(self, edges: List[List[int]]) -> int:
        return ({*edges[0]} & {*edges[1]}).pop()
