class Solution:
    def longestMountain(self, arr: List[int]) -> int:
        i, end = 0, len(arr) - 1
        max_ = 0
        while i < end:
            up = 1
            k = i
            while k < end and arr[k] < arr[k+1]:
                up += 1
                k += 1
            # Start looking for a way down if we've found a
            # way up.
            if up > 1:
                down = 0
                while k < end and arr[k] > arr[k+1]:
                    down += 1
                    k += 1
                # must have both down and up to have a mountain.
                if down:
                    max_ = max(max_, up + down)
                    i += down - 1
            # start looking again after the peak (if none were found
            # this will be == 1)
            i += up
        return max_
