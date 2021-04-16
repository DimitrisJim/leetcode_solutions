#define ALPHA_LEN 26

bool diff_contents(char *s1, char *s2) {
  // Don't create full blown set, use arrays to count occurences.
  int s1_characters[ALPHA_LEN] = {0}, s2_characters[ALPHA_LEN] = {0};
  while (*s1) {
    s1_characters[*s1++ - 97] = 1;
    s2_characters[*s2++ - 97] = 1;
  }
  for (int i = 0; i < ALPHA_LEN; i++) {
    if (s1_characters[i] != s2_characters[i]) {
      return false;
    }
  }
  return true;
}

bool areAlmostEqual(char *s1, char *s2) {
  int diff = 0;
  char *cp1 = s1, *cp2 = s2;
  // We know len s1 == len s2.
  // We must have a maximum of two characters in different
  // positions for the swap to be possible.
  while (*s1) {
    if (*s1++ != *s2++) {
      diff++;
      if (diff > 2)
        return false;
    }
  }
  // See if we have different characters in each string.
  return diff_contents(cp1, cp2);
}