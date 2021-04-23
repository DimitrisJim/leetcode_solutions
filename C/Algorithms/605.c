bool canPlaceFlowers(int *flowerbed, int flowerbedSize, int n) {
  if (n > (flowerbedSize / 2) + (1 * flowerbedSize & 1))
    return false;
  if (n == 0)
    return true;
  if (flowerbedSize == 1)
    return !*flowerbed;

  // *Mainly* done so I don't need to special case j == -1
  int i = 0;
  if (flowerbed[1] == 0) {
    if (flowerbed[0] == 0) {
      n--;
      if (n == 0)
        return true;
      i = 2;
    }
  } else {
    i = 3;
  }

  // Go through the flowerbed array.
  while (i < flowerbedSize) {
    if (*(flowerbed + i) == 0) {
      int j = i - 1, k = i + 1;
      if (*(flowerbed + j) == 0) {
        if (k < flowerbedSize) {
          if (*(flowerbed + k) == 0)
            n--;
          else {
            i += 3;
            continue;
          }
        } else
          return n <= 1;
      }
      if (n == 0)
        return true;
    }
    // Jump by two no matter the case.
    i += 2;
  }
  return n == 0;
}