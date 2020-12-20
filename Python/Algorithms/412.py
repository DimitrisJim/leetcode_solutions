class Solution:
    def fizzBuzz(self, n):
        res = []
        dm, push = divmod, res.append
        for i in range(1, n+1):
            r, m = dm(i, 3)
            if m == 0:
                # check for 5 as divisor here.
                push("Fizz" if r % 5 else "FizzBuzz")
                continue
            if i % 5:
                # if 3, 5 divided i we would catch
                # it previously
                push(f'{i}')
            else:
                push("Buzz")
        return res
