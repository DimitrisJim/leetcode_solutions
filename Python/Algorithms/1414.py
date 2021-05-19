class Solution:
    # keep pre-computed fibs around.
    fibs = [
        1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610,
        987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368,
        75025, 121393, 196418, 317811, 514229, 832040, 1346269,
        2178309, 3524578, 5702887, 9227465, 14930352, 24157817, 39088169,
        63245986, 102334155, 165580141, 267914296, 433494437, 701408733, 1134903170
    ]

    # a greedy one works?
    def findMinFibonacciNumbers(self, k: int) -> int:
        count, fibs = 0, self.fibs
        start = len(fibs) - 1
        while k >= 0:
            while k < fibs[start]:
                if (start := start - 1) == -1:
                    return count
            k -= fibs[start]
            count += 1
        return count
