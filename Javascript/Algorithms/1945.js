/**
 * @param {string} s
 * @param {number} k
 * @return {number}
 */
var getLucky = function(s, k) {
  // Populate with digits for each char of s.
  let nums = [];
  for (let c of s) {
    let val = c.charCodeAt() - 96;
    if (val < 10)
      nums.push(val);
    else {
      nums.push(Math.floor(val / 10), val % 10);
    }
  }

  // Continuously reduce until k == 1 or length == 1.
  // k > 1 because final return performs a conversion.
  while (k > 1 && nums.length > 1) {
    let sum = `${nums.reduce((a, b) => a + b)}`;
    nums = [];
    for (let c of sum) nums.push(parseInt(c));
    k--;
  }
  return nums.reduce((a, b) => a + b);
};