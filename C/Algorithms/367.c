bool isPerfectSquare(int num) {
  if (num == 1)
    return true;
  // Rough initial estimate can only be >= x.
  // Use Babylonian (?) method. Next guess is
  // arithmetic mean of [g, x/g].
  long guess = num >> 1; // int might overflow
  while (guess * guess > num)
    guess = (guess + num / guess) >> 1;
  return guess * guess == num;
}