/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numNeighbors;
 *     struct Node** neighbors;
 * };
 */

struct Node *clone(struct Node *n, struct Node **visited) {
  // return immediately if in visited.
  if (visited[n->val]) {
    return visited[n->val];
  }
  // build clone of n and place in visited.
  int neighbors = n->numNeighbors;
  struct Node *cn = malloc(sizeof(*cn));
  cn->val = n->val;
  cn->numNeighbors = neighbors;
  cn->neighbors = malloc(neighbors * sizeof(cn));
  visited[n->val] = cn;
  // recurse and add neighbors
  for (int i = 0; i < n->numNeighbors; i++)
    cn->neighbors[i] = clone(n->neighbors[i], visited);

  // return the clone.
  return cn;
}

struct Node *cloneGraph(struct Node *s) {
  // A map would be better but constraints allows
  // us to simplify thankfully.
  struct Node *visited[101] = {NULL};
  return s ? clone(s, &visited) : NULL;
}