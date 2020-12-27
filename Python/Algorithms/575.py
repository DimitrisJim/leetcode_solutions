class Solution:
    def distributeCandies(self, candyType):
        ammount, dc = len(candyType) // 2, len({*candyType})
        return dc if dc <= ammount else ammount
