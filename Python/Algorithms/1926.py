class Solution:
    def nearestExit(self, maze: List[List[str]], entrance: List[int]) -> int:
        # bfs our way out. We need shortest path among all paths.
        visited, to_visit = set(), deque([(0, tuple(entrance))])
        rows, cols = len(maze)-1, len(maze[0]) - 1

        while to_visit:
            length, pos = to_visit.popleft()
            if pos in visited:
                continue
            visited.add(pos)
            r, c = pos
            # check if this is exit from maze
            if (r in {0, rows} or c in {0, cols}):
                # not at starting position.
                if length:
                    return length
            # If not, add any directions possible.
            # up
            length += 1
            if r < rows and maze[r + 1][c] == '.':
                to_visit.append((length, (r + 1, c)))
            # down
            if r > 0 and maze[r - 1][c] == '.':
                to_visit.append((length, (r - 1, c)))
            # right
            if c < cols and maze[r][c + 1] == '.':
                to_visit.append((length, (r, c + 1)))
            # left
            if c > 0 and maze[r][c - 1] == '.':
                to_visit.append((length, (r, c - 1)))
        return -1
