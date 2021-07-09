// Note: For UnionFind structure see Structures/UnionFind/uf.c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *findRedundantConnection(int **edges, int edgesSize, int *edgesColSize,
                             int *returnSize) {
  struct UnionFind *uf = newUnionFind(0, edgesSize + 1);

  int lasts = 0, lastd = 0;
  for (int i = 0; i < edgesSize; i++) {
    int s = edges[i][0], d = edges[i][1];

    if (Find(uf, s) == Find(uf, d)) {
      lasts = s;
      lastd = d;
    } else {
      Union(uf, s, d);
    }
  }
  // We've found last source and last destination:
  *returnSize = 2;
  int *res = malloc(*returnSize * sizeof(*res));
  res[0] = lasts;
  res[1] = lastd;

  UnionFindFree(uf);
  return res;
}