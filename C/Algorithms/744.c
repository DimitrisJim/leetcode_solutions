char nextGreatestLetter(char *letters, int lettersSize, char target) {
  // Handle wrap around case (larger than largest char in letters)
  // => start from beginning again.
  if (target >= letters[lettersSize - 1])
    return *letters;

  do {
    if (target < *letters)
      break;
  } while (*letters++);
  return *letters;
}