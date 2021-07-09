struct UnionFind {
  int size;
  int *parent;
  int *rank;
};

struct UnionFind *newUnionFind(int start, int end) {
  struct UnionFind *uf = malloc(sizeof(*uf));

  uf->size = end - start;
  uf->rank = calloc(uf->size, sizeof(int));
  int *parent = malloc(uf->size * sizeof(*parent));
  for (int i = start; i < end; i++)
    parent[i] = i;
  uf->parent = parent;
  return uf;
}

int Find(struct UnionFind *uf, int a) {
  int *p = uf->parent;
  if (a == p[a])
    return a;
  // compress path
  p[a] = Find(uf, p[a]);
  return p[a];
}

void Union(struct UnionFind *uf, int a, int b) {
  int *rank = uf->rank;
  a = Find(uf, a);
  b = Find(uf, b);
  if (a != b) {
    if (rank[a] < rank[b]) {
      int tmp = a;
      a = b;
      b = tmp;
    }
    uf->parent[b] = a;
    if (rank[a] == rank[b])
      rank[a]++;
  }
}

void UnionFindFree(struct UnionFind *uf) {
  if (uf) {
    free(uf->parent);
    free(uf->rank);
    free(uf);
  }
}