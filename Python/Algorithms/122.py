class Solution:
    def maxProfit(self, prices):
        # action = 1 for buy, 0 for sell, enum would be better.
        profit, action, price = 0, 1, 0
        for i in range(1, len(prices)):
            first, second = prices[i-1], prices[i]
            # buying case
            if action == 1:
                if first < second:
                    price = first
                    action = 0  # set to sell
            # selling case
            else:
                if first > second:
                    profit = profit + first - price
                    price = 0
                    action = 1  # set to buy

        # handle the case where we're reached the end and still have
        # something to sell.
        return profit if action == 1 else profit + prices[-1] - price
