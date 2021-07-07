/**
 * @param {number[][]} graph
 * @return {number[][]}
 */
var allPathsSourceTarget = function(graph) {
  let paths = [], last = graph.length - 1, current_path = [],
      to_visit = [[0, 0]];

  while (to_visit.length > 0) {
    let [level, node] = to_visit.pop();

    if (level < current_path.length)
      current_path = current_path.slice(0, level);
    current_path.push(node);

    if (node == last) {
      paths.push(current_path);
      continue;
    }

    for (let n of graph[node]) {
      to_visit.push([level + 1, n])
    }
  }
  return paths;
};