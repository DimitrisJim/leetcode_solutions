/**
 * @param {number} x
 * @return {number}
 */
let reverse = x => {
  const to_digits = x => {
    // Build digits array for x.
    let digits = [], r = 0;
    while (x) {
      r = x % 10;
      x = floor(x / 10);
      digits.push(r);
    }
    return digits;
  }, floor = Math.floor, pow = Math.pow;

  let bound = x < 0 ? -0x80000000 : 0x7FFFFFFF;
  // Handle edge case where x is equal to largest negative which
  // cannot be represented as positive.
  if (x < 0 && x == bound) return 0;
  x = x < 0 ? -x : x;
  const x_digits = to_digits(x);
  if (x_digits.length == 10) {
    // If x has 10 digits, need to check we won't overflow. Build
    // digits array for bound
    const b_digits = to_digits(bound < 0 ? -(bound + 1) : bound);
    if (bound < 0) b_digits[0] += 1;
    // And check that digits in x are smaller.
    for (let i = 0; i < 10; i++) {
      let a = x_digits[i], b = b_digits[9 - i];
      if (a > b) return 0;
      if (a < b) break;
    }
  }
  // Build result and return it.
  let res = 0;
  for (let i = x_digits.length - 1, j = 0; i >= 0; i--, j++) {
    res += x_digits[i] * pow(10, j);
  }
  return bound < 0 ? -res : res;
};