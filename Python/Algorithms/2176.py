class Solution:
    def countPairs(self, nums: List[int], k: int) -> int:
        nums_indices = sorted(zip(nums, range(len(nums))))
        count, length = 0, len(nums)
        for i in range(length-1):
            a, aidx, b, bidx = (*nums_indices[i], *nums_indices[i+1])
            if a != b:
                continue
            if (aidx * bidx) % k == 0:
                count += 1

            # check the duplicates to see if indices are divisible by k
            j = i + 2
            while j < length:
                b, bidx = nums_indices[j]
                if a != b:
                    break
                if (aidx * bidx) % k == 0:
                    count += 1
                j += 1
        return count