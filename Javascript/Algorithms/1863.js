/**
 * @param {number[]} nums
 * @return {number}
 */
var subsetXORSum = function(nums) {
  let total = 0;
  for (let k = 1; k < 1 << nums.length; k++) {
    let subtotal = 0;
    // View subsequences as bitstrings where bit set
    // indicates we should pick a specific index.
    // We essentially generate the following sequence:
    //
    // 0, 01, 10, 11, 001, 010, 100, 011, 101, 110, 111
    //
    // and use that to index into the array (via k & (1 << i))
    // which checks if the the i'th bit is set.
    for (let i = 0; i < nums.length; i++) {
      if (k & (1 << i)) subtotal ^= nums[i];
    }
    total += subtotal;
  }
  return total;
};