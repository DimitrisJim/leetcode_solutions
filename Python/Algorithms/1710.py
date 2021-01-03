from operator import itemgetter


class Solution:
    def maximumUnits(self, boxTypes, truckSize):
        """ Greedy, fit largest until you can't. """
        boxTypes.sort(key=itemgetter(1), reverse=True)
        i, count, length = 0, 0, len(boxTypes)

        # Need both the truck to have size and for us
        # to have boxes to look at.
        while truckSize and i < length:
            num_b, num_u = boxTypes[i]
            if num_b < truckSize:
                count += num_b * num_u
                truckSize = truckSize - num_b
            else:
                return count + truckSize * num_u
            i = i + 1
        return count
