/**
 * @param {number} num
 * @return {boolean}
 */
var isPerfectSquare = function(num) {
  if (num == 1) return true;
  // Rough initial estimate can only be >= x.
  // Use Babylonian (?) method. Next guess is
  // arithmetic mean of [g, x/g].
  let guess = num >> 1;  // int might overflow
  const floor = Math.floor;
  while (guess * guess > num) guess = (guess + floor(num / guess)) >> 1;
  return guess * guess == num;
};