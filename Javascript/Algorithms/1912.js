/**
 * @param {number[]} nums
 * @return {number}
 */
var maxProductDifference = function(nums) {
  // a, b hold 1st and 2nd maxes
  let a = 0, b = 0;
  // c, d hold 1st and 2nd mins
  let c = 10 << 10, d = c;
  nums.forEach(num => {
    if (num >= a) {
      let tmp = a;
      a = num;
      b = tmp;
    } else if (num > b)
      b = num;
    if (num <= c) {
      let tmp = c;
      c = num;
      d = tmp;
    } else if (num < d)
      d = num;
  });
  return a * b - c * d;
};