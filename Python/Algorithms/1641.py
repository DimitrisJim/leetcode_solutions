class Solution:
    def _countVowelStrings(self, n):
        a, e, i, o = 5, 4, 3, 1
        while (o := o + 1) <= n:
            # heh.
            a = (a + (e := e + (i := i + (o + 1))))
        return a

    def countVowelStrings(self, n: int) -> int:
        vc, init_vals = 'aeiou', [5, 4, 3, 2, 1]
        # initial state for n == 1
        cache = dict(zip(vc, init_vals))
        sum_ = sum
        while n > 1:
            # replace new value with sum of previous.
            for i in range(5):
                c = vc[i]
                cache[c] = sum_(cache[vc[j]] for j in range(i, 5))
            n -= 1
        return cache['a']
