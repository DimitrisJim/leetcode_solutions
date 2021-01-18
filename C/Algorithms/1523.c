int countOdds(int low, int high) {
  return ((high - low) >> 1) + ((low & 1) | (high & 1));
}
