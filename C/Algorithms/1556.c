#include <stdio.h>
#include <stdlib.h>

char *thousandSeparator(int n) {
  // Length of digits in n + null terminator.
  int length = snprintf(NULL, 0, "%d", n);
  char *sn = malloc(length + 1);
  snprintf(sn, length + 1, "%d", n);
  // Can return early here.
  if (n < 1000)
    return sn;

  // Build result backwards.
  // add ammount of '.' we'll need to insert.
  int final_length = length + length / 3, count = 0;
  char *res = malloc(final_length + 1);
  // copy null terminator.
  res[final_length--] = sn[length--];
  while (final_length >= 0) {
    if (count == 3) {
      // If final_length == 0, we're done. don't
      // add additional '.', return res forwarded
      // by one pos (case happens when length % 3 == 0.)
      if (final_length == 0) {
        free(sn);
        return res + 1;
      }
      res[final_length--] = '.';
      count = 1;
    } else {
      count++;
    }
    res[final_length--] = sn[length--];
  }
  free(sn);
  return res;
}
