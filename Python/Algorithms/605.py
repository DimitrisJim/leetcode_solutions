class Solution:
    def canPlaceFlowers(self, flowerbed, n: int) -> bool:
        # Even with an empty list, the maximum amount we can place
        # is len(flowerbed) // 2 (+ 1 if odd, +0 if even)
        length = len(flowerbed)
        if n > (length // 2) + 1 * (length & 1):
            return False
        # bail early. fits everywhere.
        if n == 0:
            return True
        # bail early if [0].
        if length == 1:
            return flowerbed[0] == 0
        # Start counting from 2 pos if [_, 0, ...]
        if flowerbed[1] == 0:
            # but decrement n if [0, 0, ...]
            if flowerbed[0] == 0:
                n -= 1
                if n == 0:
                    return True
            i = 2
        # Start counting from 3rd pos if [_, 1, ...]
        else:
            i = 3
        # Go through the flower bed and check adjacent positions.
        while i < length:
            # if available, check adjacent.
            if flowerbed[i] == 0:
                j, k = i - 1, i + 1
                # previous is 0, check next and jump appropriately.
                if flowerbed[j] == 0:
                    if k < length:
                        if flowerbed[k] == 0:
                            n -= 1
                        else:
                            # jump over and go two steps over
                            # to try that slot.
                            i += 3
                            continue
                    elif k == length:
                        return n <= 1
                if n == 0:
                    return True
            # go two positions over. Either we filled it or it was
            # already a one.
            i += 2
        return n == 0
