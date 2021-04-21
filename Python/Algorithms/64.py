class Solution:
    def summaryRanges(self, nums):
        if not nums:
            return nums

        results = []
        start = end = nums[0]
        for i in nums:
            if i != end:
                rng = f"{start}->{end-1}" if start != (end - 1) else f"{start}"
                results.append(rng)
                start = end = i
            end += 1

        # we ended on a solo number.
        if start == nums[-1]:
            results.append(f'{start}')
        # we ended on a range.
        elif start != (end - 1):
            results.append(f'{start}->{end-1}')
        return results
