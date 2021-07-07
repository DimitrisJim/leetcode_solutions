class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        # dfs on the graph of rooms starting from 0.
        visited = {0}
        to_visit = [*rooms[0]]

        while to_visit:
            v = to_visit.pop()
            if v not in visited:
                to_visit.extend(rooms[v])
                visited.add(v)

        # a difference in lengths means a room isn't reachable.
        return len(visited) == len(rooms)
