/**
 * @param {number[]} flowerbed
 * @param {number} n
 * @return {boolean}
 */
let canPlaceFlowers = function(flowerbed, n) {
  const length = flowerbed.length;
  if (n > (length / 2) + (1 * length & 1)) return false;
  if (n == 0) return true;
  if (length == 1) return flowerbed[0] == 0;

  // *Mainly* done so I don't need to special case j == -1
  let i = 0;
  if (flowerbed[1] == 0) {
    if (flowerbed[0] == 0) {
      n--;
      if (n == 0) return true;
      i = 2;
    }
  } else
    i = 3;

  // Go through the flowerbed array.
  while (i < length) {
    if (flowerbed[i] == 0) {
      let j = i - 1, k = i + 1;
      if (flowerbed[j] == 0) {
        if (k < length) {
          if (flowerbed[k] == 0)
            n--;
          else {
            i += 3;
            continue;
          }
        } else
          return n <= 1;
      }
      if (n == 0) return true;
    }
    // Jump by two no matter the case.
    i += 2;
  }
  return n == 0;
};