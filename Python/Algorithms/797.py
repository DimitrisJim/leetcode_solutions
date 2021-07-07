class Solution:
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        # Level simulates our recursion depth. Allows us to adjust current path
        # accordingly (by taking prefixes of it if we find ourselves at a lower
        # level -- conceptually similar to returning from a recursive call.)
        paths, last = [], len(graph) - 1
        current_path = []
        to_visit = [(0, 0)]
        while to_visit:
            level, node = to_visit.pop()

            if level < len(current_path):
                current_path = current_path[:level]
            current_path.append(node)

            if node == last:
                paths.append(current_path)
                continue

            for i in graph[node]:
                to_visit.append((level + 1, i))
        return paths

    def _allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        path, last = [0], len(graph) - 1

        def recurse(node):
            for v in graph[node]:
                if v == last:
                    yield [*path, last]
                else:
                    path.append(v)
                    yield from recurse(v)
                    path.pop()
        return list(recurse(0))
