class Solution:

    def nextGreaterElement(self, nums1, nums2):
        """ A lot of supporting structures. """
        # Dictionary holds value -> index mapping.
        # Set just helps us keep track of what to compare.
        d, seen = {i: idx for idx, i in enumerate(nums1)}, set()
        # initialize with -1, don't need to do anything if
        # no larger element found.
        res = [-1] * len(nums1)
        add, remove = seen.add, seen.remove
        for i in nums2:
            # go through what we've seen and compare.
            for k in [*seen]:
                if i > k:
                    # if we find larger, add it to result
                    # and remove from original set.
                    res[d[k]] = i
                    remove(k)
            # if it is in d, need to add it to seen in
            # order to compare it afterwards.
            if i in d:
                add(i)
        return res

    def _meh_nextGreaterElement(self, nums1, nums2):
        d = {i: None for i in nums1}
        for idx, i in enumerate(nums2, start=1):
            if i in d:
                d[i] = nums2[idx:]
        for idx, i in enumerate(nums1):
            if d[i]:
                for j in d[i]:
                    if j > i:
                        nums1[idx] = j
                        break
                else:
                    nums1[idx] = -1
            else:
                nums1[idx] = -1
        return nums1

    def _brute_nextGreaterElement(self, nums1, nums2):
        nlen1 = len(nums1)
        res = [-1] * nlen1
        for idx, i in enumerate(nums1):
            grab = False
            for j in nums2:
                if j == i:
                    grab = True
                if grab and j > i:
                    res[idx] = j
                    break
        return res
