""" Use a condition variable to wait and signal for others to wake up.
Not sure if this is best approach, really.
"""
import threading


class Foo:
    def __init__(self):
        self.condition = threading.Condition()
        self.turn = 1

    def first(self, printFirst: 'Callable[[], None]') -> None:
        # immediately increment turn, print and then notify all waiters.
        with self.condition:
            self.turn += 1
            printFirst()
            self.condition.notify_all()


    def second(self, printSecond: 'Callable[[], None]') -> None:
        with self.condition:
            # wait around until first increments turn.
            while self.turn != 2:
                self.condition.wait()

            # increment turn and notify third.
            self.turn += 1
            printSecond()
            self.condition.notify()


    def third(self, printThird: 'Callable[[], None]') -> None:
        # waits around until notify is called from second.
        with self.condition:
            while self.turn != 3:
                self.condition.wait()
        
        printThird()