class Solution:
    def squareIsWhite(self, coordinates: str) -> bool:
        # map 'abcdefgh' to '12345678'
        normalize_col = ord(coordinates[0]) - 96
        row = int(coordinates[1])
        # white cells => one is odd other is even
        return normalize_col & 1 != row & 1 