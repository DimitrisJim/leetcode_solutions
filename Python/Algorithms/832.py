class Solution:
    def flipAndInvertImage(self, A):
        return [[i ^ 1 for i in sub] for sub in map(reversed, A)]
