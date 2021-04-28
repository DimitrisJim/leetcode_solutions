/**
 * @param {number} left
 * @param {number} right
 * @return {number}
 */
var rangeBitwiseAnd = function(left, right) {
  const floor = Math.floor;
  const bit_length = n => {
    let count = 0;
    while (n) {
      count++;
      n = floor(n / 2);
    }
    return count;
  };
  if (left == right) {
    return left;
  }

  // First property: diff bit lengths => zero.
  const bits = bit_length(left);
  if (bits < bit_length(right)) return 0;

  // Second property: result == largest common bit prefix of left+right.
  let result = 1 << (bits - 1), mask = 1 << (bits - 2);
  while (mask) {
    if ((mask & left) == (mask & right)) {
      result |= (mask & left);
    } else {
      break;
    }
    mask >>= 1;
  }
  return result;
};