#include <stdlib.h>
#include <string.h>

typedef struct {
  const char *email;
  UT_hash_handle hh;
} s_entry;

void set_add(s_entry **set, char *email) {
  s_entry *res;

  HASH_FIND_STR(*set, email, res);
  if (!res) {
    res = malloc(sizeof *res);
    res->email = email;
    HASH_ADD_KEYPTR(hh, *set, res->email, strlen(email), res);
  }
}

int numUniqueEmails(char **emails, int emailsSize) {
  s_entry *email_set = NULL;
  while (emailsSize--) {
    char *email = *emails++, *normalized, *runner;
    normalized = malloc((strlen(email) + 1) * sizeof(*normalized));
    runner = normalized;
    while (*email != '@') {
      switch (*email) {
      case '+':
        // Find '@'
        while (*email != '@')
          email++;
        break;
      case '.':
        // Advance without doing anything.
        email++;
        break;
      default:
        // Assign and advance.
        *runner++ = *email++;
      }
    }
    while (*runner++ = *email, *(++email))
      ;
    *runner = '\0';
    set_add(&email_set, normalized);
  }

  int result = HASH_COUNT(email_set);
  /* free the hash table contents */
  s_entry *s, *tmp;
  HASH_ITER(hh, email_set, s, tmp) {
    HASH_DEL(email_set, s);
    free(s); // one we made in loop.
  }
  return result;
}
