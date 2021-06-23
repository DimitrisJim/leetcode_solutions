/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *findSmallestSetOfVertices(int n, int **edges, int edgesSize,
                               int *edgesColSize, int *returnSize) {
  int *isolated = calloc(n, sizeof(*isolated));
  for (int i = 0; i < edgesSize; i++) {
    isolated[edges[i][1]]++;
  }

  // Find zeros, move them to the front of isolated and keep track
  // of their count:
  int count = 0, pos = 0;
  for (int i = 0; i < n; i++) {
    if (isolated[i] == 0) {
      isolated[pos++] = i;
      count++;
    }
  }
  // Shrink size.
  isolated = realloc(isolated, count * sizeof(int));
  *returnSize = count;
  return isolated;
}