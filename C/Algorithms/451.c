#define CHARS_LENGTH 75

int cmpi(const void *x, const void *y) {
  const int(*a)[2] = x;
  const int(*b)[2] = y;

  return -(((*a)[1] > (*b)[1]) - ((*a)[1] < (*b)[1]));
}

char *frequencySort(char *s) {
  // Counts of letters ([a-zA-Z] and digits [0-9])
  // Yes, we'll have a gap of 13 chars
  int counts[CHARS_LENGTH][2] = {0}, len = 0;
  while (*s) {
    len++;
    // Increment the count.
    int index = *s - 48;
    counts[index][0] = *s++;
    counts[index][1]++;
  }

  // Build result string (len + 1 for trailing end marker)
  char *res = malloc(len + 1), *runner;
  runner = res; // fill runner and keep res pointing at start.

  qsort(counts, CHARS_LENGTH, sizeof counts[0], cmpi);
  for (int i = 0; i < CHARS_LENGTH; i++) {
    char ch = counts[i][0];
    int count = counts[i][1];
    // stop when we reach a zero.
    if (count == 0)
      break;
    for (int j = 0; j < count; j++)
      *runner++ = ch;
  }
  *runner = '\0';
  return res;
}