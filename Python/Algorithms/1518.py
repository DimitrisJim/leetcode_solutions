class Solution:
    def numWaterBottles(self, numBottles: int, numExchange: int) -> int:
        drink, dm = numBottles, divmod
        while True:
            d, r = dm(numBottles, numExchange)
            if d == 0:
                return drink
            drink = drink + d
            numBottles = d + r
