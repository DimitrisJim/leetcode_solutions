#include <stdlib.h>
#include <string.h>

#define MAYBE_REALLOC(p, size, reqsize)                                        \
  if (reqsize > size) {                                                        \
    size *= 2;                                                                 \
    p = realloc(p, size);                                                      \
  }

char *toGoatLatin(char *S) {
  // For starters, start with a length x 3 of S.
  // its overall size strictly depends on how many
  // words we have.
  int size = (strlen(S) + 1) * 3;
  char *result = malloc(size);
  int counter = 1, length = 0;

  while (*S) {
    char first = *S++;
    if (first == ' ')
      continue;
    switch (first) {
    case 'a':
    case 'A':
    case 'i':
    case 'I':
    case 'e':
    case 'E':
    case 'u':
    case 'U':
    case 'o':
    case 'O': {
      result[length++] = first;
      // Go till the end.
      while (*S && *S != ' ') {
        MAYBE_REALLOC(result, size, length + 1);
        result[length++] = *S++;
      }
      break;
    }
    default: {
      // Go till the end.
      while (*S && *S != ' ') {
        MAYBE_REALLOC(result, size, length + 1);
        result[length++] = *S++;
      }
      result[length++] = first;
      break;
    }
    }
    MAYBE_REALLOC(result, size, (length + counter + 3));
    result[length++] = 'm';
    for (int i = 0; i < counter + 1; i++)
      result[length++] = 'a';
    // Add required space.
    result[length++] = ' ', counter++;
  }
  // Remove trailing whitespace.
  result[--length] = '\0';
  return result;
}
