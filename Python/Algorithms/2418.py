class Solution:
    def sortPeople(self, names: List[str], heights: List[int]) -> List[str]:
        return [r[1] for r in sorted(zip(heights, names), reverse=True)]