class Solution:
    def buddyStrings(self, a: str, b: str) -> bool:
        # bail early on different lengths.
        if len(a) != len(b):
            return False
        # find the indices for which char in a != char in b.
        diff = [i for i in range(len(a)) if a[i] != b[i]]

        # if we have more than 2, can't swap.
        if len(diff) > 2:
            return False
        # Might be able to swap, check chars at indices for a and b
        # to see if they contain the same character.
        elif len(diff) == 2:
            first, second = diff
            if a[first] == b[second] and a[second] == b[first]:
                return True
            return False
        # Can't do a meaningful swap here, this means one char that
        # exists in either a or b doesn't exist in the other.
        elif len(diff) == 1:
            return False
        else:
            # diff == []
            # e.g "ab" + "ba" and "aa" + "aa"
            # we use sets to check that duplicate characters exist in
            # each to be able to swap two equal characters in the string
            # i.e a with a.
            return len({*a}) < len(a) and len({*b}) < len(b)
