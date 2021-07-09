// Note: For UnionFind structure, see Structures/UnionFind/uf.js
var findRedundantConnection = function(edges) {
  let uf = new UnionFind(1, edges.length);

  let last = [];
  edges.forEach(([a, b]) => {
    if (uf.find(a) === uf.find(b))
      last = [a, b];
    else
      uf.union(a, b)
  });
  return last;
};