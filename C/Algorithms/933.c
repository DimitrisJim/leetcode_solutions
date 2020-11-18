#include <stdlib.h>

// Pending implementation.
int front(int *q);
void push_back(int *q, int el);
int pop_front(int *q);
int length(int *q);

// Pending Queue or Deque implementation.
typedef struct {
  int last_ping;
  int *pings;
} RecentCounter;

RecentCounter *recentCounterCreate() {
  RecentCounter *rc = malloc(sizeof(*rc));
  rc->last_ping = 0;
  // initialize Queue/Deque

  return rc;
}

// I've currently written this method as if obj->pings is a
// Queue. Implementation is pending.
int recentCounterPing(RecentCounter *obj, int t) {
  if ((length(obj->pings) == 0) || ((t - obj->last_ping) > 3000)) {
    push_back(obj->pings, t);
    obj->last_ping = t;
    return 1;
  }

  while (1) {
    if ((t - front(obj->pings)) <= 3000) {
      push_back(obj->pings, t);
      obj->last_ping = t;
      break;
    }
    pop_front(obj->pings);
  }
  return length(obj->pings);
}

void recentCounterFree(RecentCounter *obj) {
  if (obj) {
    free(obj->pings);
    free(obj);
  }
}
