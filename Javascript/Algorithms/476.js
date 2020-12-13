let findComplement = num => {
  let significant = 0;
  let x = num;

  // Manually count.
  while (x) {
    x = x >> 1;
    significant = (significant << 1) | 1;
  }

  return (~num) & significant;
}
