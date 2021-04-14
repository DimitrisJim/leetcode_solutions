import threading


# 36ms -> 96.39, 14.5mb -> 90.60
class FooBar:
    def __init__(self, n):
        self.n = n
        self.condition = threading.Condition()
        self.switch = 1


    def foo(self, printFoo: 'Callable[[], None]') -> None:
        cond = self.condition
        for _ in range(self.n):
            with cond:
                if not self.switch:
                    cond.wait()

                printFoo()
                # Toggle switch and notify bar.
                self.switch ^= 1
                cond.notify()


    def bar(self, printBar: 'Callable[[], None]') -> None:
        cond = self.condition      
        for _ in range(self.n):
            with cond:
                if self.switch:
                    cond.wait()

                printBar()
                # Toggle switch and notify foo.
                self.switch ^= 1
                cond.notify()