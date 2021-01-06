# Definition for Employee.
class Employee:
    def __init__(self, id: int, importance: int, subordinates):
        self.id = id
        self.importance = importance
        self.subordinates = subordinates


class Solution:
    def getImportance(self, employees, id):
        d = {e.id: [e.importance, e.subordinates] for e in employees
                if id not in e.subordinates
        }
        # get importance and subordinates
        importance, subords = d[id]

        while subords:
            subord = subords.pop()
            si, ss = d[subord]

            importance = importance + si
            if ss:
                subords.extend(ss)
        return importance
