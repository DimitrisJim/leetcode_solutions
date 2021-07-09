int findCircleNum(int **isConnected, int isConnectedSize,
                  int *isConnectedColSize) {
  int *visited = calloc((isConnectedSize + 1), sizeof(*visited)), count = 0,
      visitLength = 0, visitSize = (isConnectedSize / 2) + 1;
  int *visit = malloc(visitSize * sizeof(*visit));

  // Go through each node.
  for (int i = 1; i < isConnectedSize + 1; i++) {
    if (visited[i])
      continue;

    // Seen new component, increase count.
    visited[i] = 1;
    count++;

    // dfs on i.
    visit[visitLength++] = i;
    while (visitLength > 0) {
      int node = visit[--visitLength];
      for (int i = 1; i < isConnectedSize + 1; i++) {
        // Skip visited, those for which an edge doesn't exist or ourselves.
        if (visited[i] || isConnected[node - 1][i - 1] == 0 || i == node)
          continue;
        visited[i] = 1;
        if (visitLength + 1 == visitSize) {
          visitSize *= 2;
          visit = realloc(visit, visitSize * sizeof(*visit));
        }
        visit[visitLength++] = i;
      }
    }
  }
  free(visit);
  free(visited);
  return count;
}