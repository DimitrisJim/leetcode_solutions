#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const char *months[12] = {
    "Jan", "Feb", "Mar", "Apr", "May", "Jun",
    "Jul", "Aug", "Sep", "Oct", "Nov", "Dec",
};

// Don't much like this, seem very hard-coded.
char *reformatDate(char *date) {
  // Max size is 10 (4y-2m-2d) + 1 for trailing '\0'.
  int size = 11, year_offset = 12, month_offset = 5;
  char *result = malloc(size * sizeof(*result));
  // add end of string marker.
  *(result + --size) = '\0';

  // Add day backwards.
  // if date[1] is not a number, add '0', else add number.
  if (isalpha(date[1])) {
    *(result + --size) = date[0];
    *(result + --size) = '0';
    year_offset -= 1;
    month_offset -= 1;
  } else {
    *(result + --size) = date[1];
    *(result + --size) = date[0];
  }
  *(result + --size) = '-';

  // Add month, backwards:
  for (int i = 0; i < 12; i++) {
    if (months[i][0] == date[month_offset] &&
        months[i][1] == date[month_offset + 1] &&
        months[i][2] == date[month_offset + 2]) {
      // Found i, transform into string and place into result.
      i++;
      int length = snprintf(NULL, 0, "%d", i);
      char n[3];
      sprintf(n, "%d", i);
      if (length == 1) {
        *(result + --size) = n[0];
        *(result + --size) = '0';
      } else {
        *(result + --size) = n[1];
        *(result + --size) = n[0];
      }
      *(result + --size) = '-';
      break;
    }
  }

  // Advance past month and space to add year:
  date += year_offset;
  for (int i = 0; i < 4; i++)
    *(result + --size) = *date--;

  return result;
}
