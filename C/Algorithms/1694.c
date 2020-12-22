#include <stdlib.h>

// Count numbers in s.
#define COUNT_NUMS(s, counter)                                                 \
  do {                                                                         \
    if (*s != '-' && *s != ' ')                                                \
      counter++;                                                               \
  } while (*(++s));

char *reformatNumber(char *number) {
  int len = 0;
  char *runner = number;
  COUNT_NUMS(runner, len);

  // Find how many times to repeat and what will be left.
  int left = len, repeat = 0;
  while (left > 4) {
    left -= 3;
    repeat++;
  }

  // Find resulting size -> len digits + repeat dashes + 1 if 4 left.
  // rlen keeps track of length of result.
  int resSize = len + repeat + 1 + (left == 4 ? 1 : 0), rlen = 0;
  char *result = malloc(resSize + 1); // keep space for '\0'

  // Add triplets, takes care of a number of edge cases:
  //  digits -> keep track of how many digits we've added so far (
  //            to know when to move to next group.)
  //  end    -> flag, re-use the while loop to also add left overs.
  //  lim    -> how many digits to we add? 3 or 2.
  //  repeat needs to be re-adjusted for the case where repeat == 0
  //  and left == 4. We want to repeat twice even though repeat has
  // initially been set to 0.
  int digits = 0, end = repeat > 0 ? 0 : 1,
      lim = repeat > 0 ? 3 : (left == 4 ? 2 : left);
  repeat = repeat > 0 ? repeat : (left == 4 ? 2 : 0);
  while (1) {
    // Skip '-' and ' '.
    while (*number && *number == '-' || *number == ' ')
      number++;

    // Add dash and, if we have leftovers, handle them, else break.
    if (digits == lim) {
      result[rlen++] = '-';
      digits = 0;
      repeat--;
      if (repeat <= 0) {
        if (end)
          break;
        repeat = left == 4 ? 2 : 1;
        lim = left == 4 ? 2 : left;
        end = 1;
      }
      // Add digit.
    } else {
      result[rlen++] = *number++;
      digits++;
    }
  }
  // Replace superflous '-' added with terminator.
  result[--rlen] = '\0';
  return result;
}
