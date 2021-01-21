class Solution:
    def detectCapitalUse(self, word):
        if len(word) == 1:
            return True

        up, low = str.isupper, str.islower
        if up(word[0]):
            if up(word[1]):
                return all(up(i) for i in word)
            return all(low(i) for i in word[1:])
        return all(low(i) for i in word)
