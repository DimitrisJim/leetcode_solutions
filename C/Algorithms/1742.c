#include <stdlib.h>

// Note brackets: need a new local namespace for base.
#define ADD_FROM_BASE(arr, n, start, end)                                      \
  {                                                                            \
    int base = count_digits(n);                                                \
    for (int i = start; i < end; i++)                                          \
      (*(arr + base + i))++;                                                   \
  }

// Count digits in int n.
inline int count_digits(int n) {
  int sum = 0;
  while (n) {
    sum += n % 10;
    n /= 10;
  }
  return sum - 1;
}

// Return zero initialized array for storing counts.
// Caller responsible for free-ing array.
int *init_counter(int n, int *counter_size) {
  int slots = 18;
  if (n > 10000)
    slots = 45;
  else if (n > 1000)
    slots = 36;
  else
    slots = 27;
  // Set size for caller.
  *counter_size = slots;
  return calloc(slots, sizeof(int));
}

int countBalls(int lowLimit, int highLimit) {
  int aLen = 0;
  int *a = init_counter(highLimit, &aLen);

  int start = lowLimit / 10, start_left = lowLimit % 10,
      end = (highLimit + 1) / 10, end_left = (highLimit + 1) % 10;

  // start == end -> we're on the same multiple of ten. add
  // range [start_left, end_left) and be done.
  if (start == end)
    ADD_FROM_BASE(a, start, start_left, end_left)
  // Not on same multiple. Add [start_left, 10) and [0, end_left)
  // and then go through [lowLimit, highLimit] in multiples of ten.
  else {
    ADD_FROM_BASE(a, start, start_left, 10);
    ADD_FROM_BASE(a, end, 0, end_left);

    start = (start + 1) * 10;
    end = (end - 1) * 10;
    for (int i = start; i <= end; i += 10) {
      ADD_FROM_BASE(a, i, 0, 10);
    }
  }
  // Find max and return it.
  int max = a[0];
  for (int i = 1; i < aLen; i++) {
    if (a[i] > max)
      max = a[i];
  }
  free(a);
  return max;
}
