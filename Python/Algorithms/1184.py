class Solution:
    def distanceBetweenBusStops(self, distance, start, dest):
        sts = std = ste = 0
        i = 1
        for j in distance:
            if i <= start:
                sts = sts + j
            if i <= dest:
                std = std + j
            ste = ste + j
            i = i + 1

        if dest < start:
            diff = sts - std
        else:
            diff = std - sts
        return min(diff, ste - diff)
