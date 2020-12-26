from collections import deque

class Solution:
    def countStudents(self, students, sandwiches):
        students, sandwiches = deque(students), deque(sandwiches)
        i = 0

        while i != len(students):
            if students[0] == sandwiches[0]:
                students.popleft()
                sandwiches.popleft()
                i = 0
            else:
                students.rotate(-1)
                i += 1
        return len(students)
