/**
 * @param {number} n
 * @param {number[][]} edges
 * @return {number[]}
 */
var findSmallestSetOfVertices = function(n, edges) {
  let counts = Array(n).fill(0), isolated = [];
  edges.forEach(([_, dest]) => counts[dest]++);

  // Only grab indices with count[i] == 0
  counts.forEach((v, i) => {
    if (v == 0) isolated.push(i);
  });
  return isolated;
};