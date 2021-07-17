/**
 * @param {number} n
 * @return {number}
 */
var countTriples = function(n) {
  // precompute all powers from
  let count = 0, pows = [];
  const pow = Math.pow, sqrt = Math.sqrt;
  for (let i = 3; i < n; i++) pows[i] = pow(i, 2);

  for (let i = 3; i < n - 1; i++) {
    let si = pows[i];
    for (let j = i + 1; j < n; j++) {
      // c must be integer (perfect square)
      let m = sqrt(si + pows[j]);
      // j only increases, cannot find m > n.
      if (m > n) {
        // means m was > n during first iteration,
        // i.e for consequent iterations it will
        // always be > n.
        if (j == i + 1) {
          return count * 2;
        }
        break;
      }
      // m <= n (wasn't aware of this mod trick.)
      if (m % 1 === 0) count++
    }
  }
  return count * 2;
};