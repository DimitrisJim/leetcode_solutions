/**
 * @param {number[][]} isConnected
 * @return {number}
 */
var findCircleNum = function(isConnected) {
  let visited = Array(isConnected.length + 1).fill(0), count = 0;
  for (let i = 1; i < isConnected.length + 1; i++) {
    if (visited[i]) continue;
    // Seen new component, increase count.
    visited[i] = 1;
    count++;

    // dfs on i.
    let visit = [i];
    while (visit.length > 0) {
      let node = visit.pop();
      isConnected[node - 1].forEach((v, index) => {
        index++;
        if (!(visited[index] || v == 0 || index == node)) {
          visited[index] = 1;
          visit.push(index);
        }
      });
    }
  }
  return count;
};