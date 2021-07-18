/**
 * @param {character[][]} maze
 * @param {number[]} entrance
 * @return {number}
 */
var nearestExit = function(maze, entrance) {
  // Dunno why but couldn't get this to work with a set.
  let to_visit = Queue.fromArray([[0, entrance]]), rows = maze.length - 1,
      cols = maze[0].length - 1, visited = [];
  for (let i = 0; i < rows + 1; i++) {
    visited.push(Array(cols + 1).fill(0));
  }
  while (!to_visit.isEmpty()) {
    let [length, [r, c]] = to_visit.dequeue();
    if (visited[r][c]) continue;
    visited[r][c] = 1;

    // check if this is exit from maze
    if ((r == 0 || r == rows) || (c == 0 || c == cols)) {
      // not at starting position.
      if (length) return length;
    }
    // If not, add any directions possible.
    // up
    length += 1;
    if (r < rows && maze[r + 1][c] == '.')
      to_visit.enqueue([length, [r + 1, c]]);
    // down
    if (r > 0 && maze[r - 1][c] == '.') to_visit.enqueue([length, [r - 1, c]]);
    // right
    if (c < cols && maze[r][c + 1] == '.')
      to_visit.enqueue([length, [r, c + 1]]);
    // left
    if (c > 0 && maze[r][c - 1] == '.') to_visit.enqueue([length, [r, c - 1]]);
  }
  return -1;
};