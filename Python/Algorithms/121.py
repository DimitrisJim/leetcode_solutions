class Solution:
    def maxProfit(self, prices):
        """
        Continuously holds the minimum encountered thus far. When a
        value is not smaller, we see if it exceeds the max_price as
        has been set thus far. For example:

        px: [1, 2, 3, 0, 20, 0, 30, 5, 6]

        min_price is initialized to prices[0] first (by default, the minimum
        encountered thus far). Our max_price during the iteration tracks the
        following subtractions:

        For price == 1: => min_price = 1, max_price = 0 (dummy iteration, really)
            price == 2: => min_price = 1, max_price = 1 (2 - 1)
            price == 3: => min_price = 1, max_price = 2 (3 - 1)
            ....
            price == 30 => min_price = 0, max_price = 30 (30 - 0). (Final answer)  

        Runs in O(N) with O(1) space.
        """
        max_ = max
        max_price, min_price = 0, prices[0]
        for price in prices:
            if price <= min_price:
                min_price = price
            else:
                max_price = max_(max_price, price - min_price)
        return max_price
