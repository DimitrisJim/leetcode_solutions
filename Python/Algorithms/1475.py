class Solution:
    def finalPrices(self, prices):
        length = len(prices)
        range_ = range
        # from 0 until second from last (last element)
        # doesn't need to be checked.
        for i in range_(length - 1):
            # toggle to see if we appended something
            appended = False
            val = prices[i]
            # check and last element
            for j in range_(i+1, length):
                if prices[j] <= val:
                    prices[i] = val - prices[j]
                    appended = not appended
                    break
            # if not, append.
            if not appended:
                prices[i] = val

        return prices
