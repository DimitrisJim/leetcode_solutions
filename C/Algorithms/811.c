#include "uthash/src/uthash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to hold our counts.
typedef struct {
  const char *domain;
  int value;
  UT_hash_handle hh;
} m_entry;

// Adds domain. Value updated if there.
void add_domain(m_entry **domains, const char *domain, int value) {
  m_entry *s;
  HASH_FIND_STR(*domains, domain, s);
  if (!s) {
    s = malloc(sizeof(*s));
    // Note: we control allocated domain now, need to free it.
    s->domain = domain;
    s->value = value;
    HASH_ADD_KEYPTR(hh, *domains, s->domain, strlen(s->domain), s);
    // If it is already inside our map, update the value.
  } else {
    s->value += value;
  }
}

// Free domains and return elements in format needed.
inline char **to_char_vec(m_entry **domains, int *returnSize) {
  // set returnSize and initialize needed variables.
  *returnSize = HASH_COUNT(*domains);
  char **res = malloc(*returnSize * sizeof(*res));
  m_entry *ce, *tmp;
  int i = 0;
  HASH_ITER(hh, *domains, ce, tmp) {
    // For some reason, sprintf doesn't do it for me.
    int size = snprintf(NULL, 0, "%d %s", ce->value, ce->domain) + 1;
    char buf[size];
    res[i] = malloc(size);
    snprintf(buf, sizeof buf, "%d %s", ce->value, ce->domain);
    strncpy(res[i++], buf, size);

    // Delete the entries after we're done with them.
    HASH_DEL(*domains, ce);
    free((void *)ce->domain);
    free(ce);
  }
  return res;
}

// Get value by finding where ' ' lies. Return split_point for us to advance to
// it.
inline int get_value(char *s, int *split_point) {
  int count_len = 0;
  char *adv = s, *tmp;
  while (*adv++ != ' ')
    count_len++;

  // Copy string value over.
  tmp = malloc((count_len + 1) * sizeof(*tmp));
  strncpy(tmp, s, count_len);
  tmp[count_len] = '\0';
  *split_point = count_len;

  // And return it.
  count_len = atoi((const char *)tmp);
  free(tmp);
  return count_len;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **subdomainVisits(char **cpdomains, int cpdomainsSize, int *returnSize) {
  m_entry *domains = NULL;
  for (int i = 0; i < cpdomainsSize; i++) {
    char *cpd = cpdomains[i];

    // Find value.
    int split_point, s_len = strlen(cpd);
    int value = get_value(cpd, &split_point);

    // Find bottom-level domain.
    // NOTE: I believe it's all sloppy. Could probably go better
    // with this.
    int diff = s_len - split_point;
    char *domain = malloc((diff + 1) * sizeof(*domain));
    strncpy(domain, cpd + (split_point + 1), diff);
    domain[diff] = '\0';
    // Add to domains mapping, it is responsible for freeing it.
    add_domain(&domains, (const char *)domain, value);

    // Advance cpd past split_point.
    cpd = cpd + (split_point + 1);
    // Add any other domains.
    while (split_point++, *cpd++) {
      // Bumped into a '.'.
      if (*cpd == '.') {
        diff = s_len - split_point;
        domain = malloc((diff + 1) * sizeof(*domain));
        strncpy(domain, cpd + 1, diff);
        domain[diff] = '\0';
        // Add to domains mapping, it is now responsible for freeing it.
        add_domain(&domains, (const char *)domain, value);
      }
    }
  }
  // Free domains and return as char **; set returnSize to HASH_COUNT.
  return to_char_vec(&domains, returnSize);
}
