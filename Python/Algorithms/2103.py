class Solution:
    def countPoints(self, rings: str) -> int:
        GREEN, RED, BLUE = 1, 2, 4
        rods = [0] * 10
        
        for i in range(1, len(rings), 2):
            color, rod = rings[i-1], rings[i]
            if color == 'R':
                b = RED
            elif color == 'B':
                b = BLUE
            else:
                b = GREEN
            rods[int(rod)] |= b
            
        # RED | BLUE | GREEN == 7
        return sum(i == 7 for i in rods)