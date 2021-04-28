int bit_length(int n) {
  int count = 0;
  while (n) {
    count++;
    n /= 2;
  }
  return count;
}

int rangeBitwiseAnd(int left, int right) {
  if (left == right) {
    return left;
  }

  // First property: diff bit lengths => zero.
  int bits = bit_length(left);
  if (bits < bit_length(right))
    return 0;

  // Second property: result == largest common bit prefix of left+right.
  int result = 1 << (bits - 1), mask = 1 << (bits - 2);
  while (mask) {
    if ((mask & left) == (mask & right)) {
      result |= (mask & left);
    } else {
      break;
    }
    mask >>= 1;
  }
  return result;
}