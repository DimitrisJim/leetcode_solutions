/**
 * @param {number} x
 * @return {number}
 */
var mySqrt = function(x) {
  if (x == 1) return 1;
  // Rough initial estimate can only be >= x.
  // Use Babylonian (?) method. Next guess is
  // arithmetic mean of [g, x/g].
  let guess = x >> 1;  // int might overflow
  const floor = Math.floor;
  while (guess * guess > x) guess = (guess + floor(x / guess)) >> 1;
  return guess;
};