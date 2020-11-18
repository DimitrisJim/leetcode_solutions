from collections import deque


class RecentCounter:

    def __init__(self):
        self.req = deque()
        self.last_ping = 0

    def ping(self, t):
        req = self.req
        if not req or (t - self.last_ping > 3000):
            self.last_ping = t
            req.clear()
            req.appendleft(t)
            return 1

        req = self.req
        while True:
            if t - req[-1] > 3000:
                req.pop()
            else:
                req.appendleft(t)
                self.last_ping = t
                return len(req)
