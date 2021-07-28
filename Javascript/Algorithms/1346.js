/**
 * @param {number[]} arr
 * @return {boolean}
 */
var checkIfExist = function(arr) {
  let nums = new Set;
  for (let num of arr) {
    if (nums.has(num * 2)) return true;
    let half = num / 2;
    if (half % 1 == 0 && nums.has(half)) return true;
    nums.add(num);
  }
  return false;
};