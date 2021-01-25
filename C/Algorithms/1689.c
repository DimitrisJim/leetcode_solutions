int minPartitions(char *n) {
  // Find max digit in n.
  int dig = *n++;
  while (*n) {
    int d = *n++;
    if (d > dig)
      dig = d;
  }
  return dig - '0';
}
