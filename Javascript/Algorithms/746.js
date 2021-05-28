/**
 * @param {number[]} cost
 * @return {number}
 */
var minCostClimbingStairs = function(cost) {
  const min = Math.min;
  let cost_len = cost.length, table_len = cost_len + 2,
      table = Array(table_len).fill(2 << 20);
  table[0] = 0;

  for (let i = 1; i < table_len; i++) {
    let prev = table[i - 1];
    table[i] = min(table[i], prev + (i < cost_len ? cost[i - 1] : 0));
    let j = i + 1;
    if (j < table_len)
      table[j] = min(table[j], prev + (i < cost_len ? cost[i] : 0));
  }
  // return final element.
  return table[table_len - 1];
};