/**
 * Forward declaration of guess API.
 * @param {number} num   your guess
 * @return 	            -1 if num is lower than the guess number
 *			             1 if num is higher than the guess number
 *                       otherwise return 0
 * var guess = function(num) {}
 */

/**
 * @param {number} n
 * @return {number}
 */
var guessNumber = function(n) {
  const floor = Math.floor;
  let start = 0, end = n;
  while (1) {
    let mid = floor((start + end) / 2);
    let res = guess(mid);
    if (res == 0)
      return mid;
    else if (res == -1)
      end = mid;
    else
      start = mid + 1;
  }
};