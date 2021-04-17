#define RES_LEN 8
static char res[RES_LEN + 1];

char *toHex(int num) {
  if (num == 0) {
    // Set result to 0 and return.
    res[0] = '0';
    res[1] = '\0';
    return res;
  }
  // Build map from {0, 1, ..., e, f} to their code point values.
  int charMap[16] = {0}, i = 0;
  char *s = "0123456789abcdef", tmp[RES_LEN + 1];
  while (*s)
    charMap[i++] = *s++;

  /*
  Fill the temp char array with the values. We work
  with 4 bit sequences each time (num & 15, num >>= 4) and
  use the charMap to look-up the appropriate value.
  With 2's complement, negative numbers appear as an infinite
  sequence of ones stretching to the left, so we cap it with
  size. (set to 8, the number of 4bit sequences for a 32bit number).
  */
  int size = RES_LEN;
  while (num && size > 0) {
    tmp[RES_LEN - size] = charMap[num & 15];
    num >>= 4;
    size--;
  }
  // Tmp has results reversed, reverse them.
  for (int i = RES_LEN - size - 1, j = 0; i >= 0; i--, j++)
    res[j] = tmp[i];

  // Set marker at the end and return.
  res[RES_LEN - size] = '\0';
  return res;
}