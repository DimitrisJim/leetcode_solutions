class Solution:
    def isPathCrossing(self, path):
        points, current_pos = {(0, 0)}, (0, 0)
        for d in path:
            if d == 'W':
                current_pos = current_pos[0], current_pos[1] + 1
            elif d == 'E':
                current_pos = current_pos[0], current_pos[1] - 1
            elif d == 'N':
                current_pos = current_pos[0] + 1, current_pos[1] 
            else:
                current_pos = current_pos[0] - 1, current_pos[1] 
            if current_pos in points:
                return True
            points.add(current_pos)
        return False
