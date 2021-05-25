/**
 * @param {number} n
 * @return {number}
 */
// digits until 10 * i for i in {1..9}
const limits =
    [9, 189, 2889, 38889, 488889, 5888889, 68888889, 788888889, 8888888889];

var findNthDigit = function(n) {
  if (n < 10) return n;

  const floor = Math.floor, pow = Math.pow;
  let i = 0;
  while (n > limits[i]) i++;

  // need the largest value smaller than n.
  let digits_left = n - (limits[i - 1] + 1);
  // i == 0 => 1 digits. i == 1 => 2 digits..
  let pos = floor(digits_left / (i + 1)), digit = digits_left % (i + 1);
  // get digit at position digit with typical while loop.
  return parseInt(`${pow(10, i) + pos}`[digit]);
};