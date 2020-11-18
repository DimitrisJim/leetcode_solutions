class OrderedStream:

    def __init__(self, n):
        self.ptr = 1
        self.vals = {}
 
    def insert(self, id, value):
        res, vals, p = [], self.vals, self.ptr
        vals[id] = value
        # if None, we stop.
        while (val:= vals.get(p)):
            res.append(val)
            p = p + 1
        self.ptr = p
        return res
