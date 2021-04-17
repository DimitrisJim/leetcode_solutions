uint32_t reverseBits(uint32_t n) {
  // count leading_zeros -- i.e zero bits at the beginning
  // of n. (where n is assumed 32bit)
  uint32_t c = 1u << 31;
  uint32_t rev = 0, leading_zeros = 0;
  while (n && ((n & c) == 0)) {
    leading_zeros++;
    c >>= 1;
  }
  // after finding leading_zeros, go through n and add
  // set bits (n & 1) to rev. rev is shifted left while
  // n is shifted right.
  while (n) {
    rev = (rev << 1) | n & 1;
    n >>= 1;
  }
  return rev << leading_zeros;
}