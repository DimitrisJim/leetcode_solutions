/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

int guessNumber(int n) {
  uint start = 0, end = n, mid;
  while (1) {
    mid = (start + end) / 2;
    int res = guess(mid);
    if (res == 0)
      break;
    else if (res == -1)
      end = mid;
    else
      start = mid + 1;
  }
  return mid;
}