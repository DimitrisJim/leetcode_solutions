class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        visited = [0] * (len(isConnected) + 1)
        count = 0
        for i in range(1, len(isConnected)+1):
            if visited[i]:
                continue
            # Seen new component, increase count.
            visited[i] = 1
            count += 1

            # dfs on i.
            visit = [i]
            while visit:
                node = visit.pop()
                for i, v in enumerate(isConnected[node-1], start=1):
                    if visited[i] or v == 0 or i == node:
                        continue
                    visited[i] = 1
                    visit.append(i)
        return count
