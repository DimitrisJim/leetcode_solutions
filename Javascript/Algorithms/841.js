/**
 * @param {number[][]} rooms
 * @return {boolean}
 */
var canVisitAllRooms = function(rooms) {
  let visited = new Set, to_visit = [...rooms[0]];


  visited.add(0);
  while (to_visit.length > 0) {
    let v = to_visit.pop();
    if (!visited.has(v)) {
      to_visit.push(...rooms[v]);
      visited.add(v);
    }
  }

  return visited.size == rooms.length;
};