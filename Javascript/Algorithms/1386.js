/**
 * @param {number} lo
 * @param {number} hi
 * @param {number} k
 * @return {number}
 */
var getKth = function(lo, hi, k) {
  let cache = new Map;
  const floor = Math.floor, power_x = (x) => {
    if (x == 1) return 1;
    if (cache.has(x))
      return cache.get(x);
    else if (x & 1) {
      cache.set(x, power_x(3 * x + 1) + 1);
    } else {
      cache.set(x, power_x(floor(x / 2)) + 1);
    }
    return cache.get(x);
  };
  let powers = [];
  for (let i = lo; i <= hi; i++) {
    powers.push([i, power_x(i)]);
  }
  powers.sort((x, y) => x[1] - y[1]);
  return powers[k - 1][0];
};