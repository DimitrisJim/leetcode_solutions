""" The logic is similar to the others. Wait around until our value is ready;
when that happens, we invoke the callable, change the state (self.val) and notify
the others. 

Not sure if it is the best approach.
"""
import threading


# 24 -> 95.62, 14.8 - 44.11
class FizzBuzz:
    def __init__(self, n: int):
        self.n = n
        self.cv = threading.Condition()
        self.val = 1
        
    # printFizz() outputs "fizz"
    def fizz(self, printFizz: 'Callable[[], None]') -> None:
        cv = self.cv
        while self.val <= self.n:
            with cv:
                while not (self.val % 3 == 0 and self.val % 5 != 0):
                    cv.wait()
                    if self.val > self.n:
                        return
                printFizz()
                self.val += 1
                cv.notify_all()

    # printBuzz() outputs "buzz"
    def buzz(self, printBuzz: 'Callable[[], None]') -> None:
        cv = self.cv
        while self.val <= self.n:
            with cv:
                while not (self.val % 5 == 0 and self.val % 3 != 0):
                    cv.wait()
                    if self.val > self.n:
                        return
                printBuzz()
                self.val += 1
                cv.notify_all()

    # printFizzBuzz() outputs "fizzbuzz"
    def fizzbuzz(self, printFizzBuzz: 'Callable[[], None]') -> None:
        cv = self.cv
        while self.val <= self.n:
            with cv:
                while not (self.val % 3 == 0 and self.val % 5 == 0):
                    cv.wait()
                    if self.val > self.n:
                        return
                printFizzBuzz()
                self.val += 1
                cv.notify_all()

    # printNumber(x) outputs "x", where x is an integer.
    def number(self, printNumber: 'Callable[[int], None]') -> None:
        cv = self.cv
        while self.val <= self.n:
            with cv:
                while self.val % 3 == 0 or self.val % 5 == 0:
                    cv.wait()
                    if self.val > self.n:
                        return
                printNumber(self.val)
                self.val += 1
                cv.notify_all()