class Solution:
    def nextGreatestLetter(self, letters, target: str) -> str:
        # handle wrap around case.
        if target >= letters[-1]:
            return letters[0]

        for c in letters:
            if c > target:
                return c
