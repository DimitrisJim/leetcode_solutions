char *convertToBase7(int num) {
  if (num == 0)
    return "0";

  bool neg = num > 0 ? false : true;
  num = num > 0 ? num : -num;

  // Space for digits, end marker and neg sign if applicable.
  int len = 0, size = snprintf(NULL, 0, "%d", num) + 1 + (neg ? 1 : 0);
  char *digits = malloc(size + 1);
  if (neg) {
    digits[len++] = '-';
  }
  while (num > 0) {
    // Transforms to char. ord of 48 is '0'.
    // Some numbers in base 10 lead to larger (more digits) in base 7.
    if (len >= size) {
      size += 4;
      digits = realloc(digits, size);
    }
    digits[len++] = (num % 7) + '0';
    num /= 7;
  }
  digits[len] = '\0';

  // Reverse digits
  int start = 0;
  if (neg) {
    start = 1;
  }
  for (int i = start, j = len - 1; i < j; i++, j--) {
    char temp = digits[i];
    digits[i] = digits[j];
    digits[j] = temp;
  }
  return digits;
}