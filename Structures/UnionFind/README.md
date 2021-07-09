## Disjoint Set Union

Implements a tiny structure for DSU/UnionFind operations. Uses a backing array (which means
we work with nodes in the set of natural numbers, including zero).

Supports only creation, `union` and `find` (and `free` for C). Uses path compression and union by rank.

Not meant to be as robust and feature rich as they could, meant only for solving related problems.