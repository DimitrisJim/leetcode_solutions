import threading


# 28 - 98.52, 15.6 - 36.67
class ZeroEvenOdd:
    def __init__(self, n):
        self.n = n
        self.turn = 0
        self.cv = threading.Condition()
        self.odds = (i for i in range(1, n + 1) if i & 1)
        self.evens = (i for i in range(1, n + 1) if not i & 1)
        
        
	# printNumber(x) outputs "x", where x is an integer.
    def zero(self, printNumber: 'Callable[[int], None]') -> None:
        odd = True
        cv = self.cv
        for _ in range(self.n):
            with cv:
                while self.turn:
                    cv.wait()

                printNumber(0)
                self.turn = 1 if odd else 2
                odd = not odd
                cv.notify_all()
        
        
    def even(self, printNumber: 'Callable[[int], None]') -> None:
        cv = self.cv
        for _ in range(self.n // 2):
            with cv:
                while self.turn != 2:
                    cv.wait()
                self.turn = 0
                printNumber(next(self.evens))
                cv.notify_all()
        
    def odd(self, printNumber: 'Callable[[int], None]') -> None:
        cv = self.cv
        # need to add one if n is odd.
        for _ in range((self.n // 2) + (self.n & 1)):
            with cv:
                while self.turn != 1:
                    cv.wait()
                self.turn = 0
                printNumber(next(self.odds))
                cv.notify_all()