int findComplement(unsigned num) {
  // Finds number of leading zeros.
  // See 5.3 hackers delight.
  if (num == 0) {
    return 1;
  }
  unsigned n = 0, x = num;
  if (x <= 0x0000FFFF) {
    n = n + 16;
    x = x << 16;
  }
  if (x <= 0x00FFFFFF) {
    n = n + 8;
    x <<= 8;
  }
  if (x <= 0x0FFFFFFF) {
    n = n + 4;
    x = x << 4;
  }
  if (x <= 0x3FFFFFFF) {
    n = n + 2;
    x = x << 2;
  }
  if (x <= 0x7FFFFFFF) {
    n = n + 1;
  }

  // Invert it and keep around one's
  return ~num & 0xFFFFFFFF >> n;
}
