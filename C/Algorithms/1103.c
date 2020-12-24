#include <stdlib.h>

// Array after k steps.
int *array_until_k(int k, int n) {
  int *result = malloc(n * sizeof(*result));
  for (int i = 1; i < n + 1; i++) {
    result[i - 1] = ((k + 1) * i) + ((k * (k + 1)) >> 1) * n;
  }
  return result;
}

// Sum of the array after k steps.
long sum_until_k(int k, int n) {
  long sum = 0;
  for (int i = 1; i < n + 1; i++)
    sum += ((k + 1) * i) + ((k * (k + 1)) >> 1) * n;
  return sum;
}

// A best guess for k if c is large (so we don't compute every single sum.)
int best_guess_k(int c, int n) {
  int k = 0, ammount;
  if (c <= 100)
    return k;
  else if (c <= 1000)
    ammount = 2;
  else if (c <= 100000)
    ammount = 10;
  else if (c <= 10000000)
    ammount = 50;
  else
    ammount = 250;

  while (1) {
    long sum = sum_until_k(k, n);
    if (sum < c)
      k += ammount;
    // Go back and return.
    else {
      k -= ammount;
      break;
    }
  }
  return k;
}

// Note: The returned array must be malloced, assume caller calls free().
int *distributeCandies(int candies, int n, int *returnSize) {
  // Set from here, we might return early.
  *returnSize = n;

  // prev holds value < candies. next holds value >= candies.
  // k denotes how many times we've gone through the array of size n.
  long prev = 0, next = 0;
  int k = best_guess_k(candies, n);
  while (candies >= next) {
    prev = next;
    next = sum_until_k(k++, n);
  }
  // We can return, exact match.
  if (candies == next)
    return array_until_k(k - 1, n);

  // Hold leftover value of candies.
  // k - 2 so we can go to the value of k that generated prev.
  int left = candies - prev;
  k = k - 2 > 0 ? k - 2 : 0;
  // prev might be 0 (candies < n), initialize result to zeros, then.
  int *result;
  if (prev == 0) {
    result = calloc(n, sizeof(*result));
    // Needed for when we calculate next values in the
    // following loop. (i.e if prev == 0, k == 0 and so we
    // need k == 1 in the next loop.)
    k = k - 1;
    // Build array for prev.
  } else
    result = array_until_k(k, n);

  // Add leftovers now:
  k = k + 1;
  for (int i = 1; i < n + 1; i++) {
    // to_add = result_k_[i] - result_k-1_[i]
    int to_add = (((k + 1) * i) + ((k * (k + 1)) >> 1) * n) - result[i - 1];
    if (to_add >= left) {
      result[i - 1] += left;
      break;
    }
    result[i - 1] += to_add;
    left -= to_add;
  }
  return result;
}
