void strlen_and_unique_len(char *p, int *res_len, int *res_unique_len) {
  int chars[26] = {0}, unique_len = 0, len = 0;
  while (*p) {
    len++;
    int i = *p++ - 97;
    if (chars[i] == 0) {
      unique_len++;
      chars[i] = 1;
    }
  }
  *res_len = len;
  *res_unique_len = unique_len;
}

bool buddyStrings(char *a, char *b) {
  // Find indices where strings differ.
  int diffs[2] = {-1, -1}, index = 0, diff_track = 0;
  char *cpa = a, *cpb = b;
  while (*cpa) {
    // if cpb reaches null, length mismatch, return.
    if (!*cpb)
      return false;
    if (*cpa++ != *cpb++) {
      // If we have more than 2 diffs, return false,
      // can't do swap.
      if (diff_track == 2) {
        return false;
      }
      diffs[diff_track++] = index;
    }
    index++;
  }
  // Both need to have been exhausted, if cpb still points
  // to something, it means lengths differ.
  if (*cpb) {
    return false;
  }

  if (diff_track == 2) {
    // See if characters in indices are the same.
    int first = diffs[0], second = diffs[1];
    if ((a[first] == b[second]) && (a[second] == b[first]))
      return true;
    return false;
  } else if (diff_track == 1) {
    return false;
  } else {
    // No diffs. This leads to two cases:
    //  - a == b and both a, b have unique chars => we can't do any swaps.
    //  - a == b and a and b have duplicate chars => swap duplicates.
    // We can use sets to see if dups exist and if so return True.
    int a_len = 0, a_unique_len = 0;
    int b_len = 0, b_unique_len = 0;
    strlen_and_unique_len(a, &a_len, &a_unique_len);
    strlen_and_unique_len(b, &b_len, &b_unique_len);
    return a_unique_len < a_len && b_unique_len < b_len;
  }
}