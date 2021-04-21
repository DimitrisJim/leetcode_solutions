#define MAYBE_REALLOC(ptr, required, size)                                     \
  if (required >= size) {                                                      \
    size *= 2;                                                                 \
    ptr = realloc(ptr, size * sizeof(*ptr));                                   \
  }

// end == -1 signals only single result with start.
char *make_range(int start, int end, bool include_end) {
  int len_start = snprintf(NULL, 0, "%d", start);
  char *res = malloc(len_start + 1);
  int written = snprintf(res, len_start + 1, "%d", start);

  // Write end to res.
  if (include_end) {
    int len_end = snprintf(NULL, 0, "%d", end);
    // Reallocate res, add 2 for the -> character.
    res = realloc(res, len_start + 1 + len_end + 2);
    written += snprintf(res + written, 3, "%s", "->");
    snprintf(res + written, len_end + 1, "%d", end);
  }
  return res;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **summaryRanges(int *nums, int numsSize, int *returnSize) {
  if (numsSize == 0) {
    *returnSize = 0;
    return NULL;
  }

  int result_size = 2, num_ranges = 0;
  uint start = nums[0], end = nums[0];
  char *rng, **result = malloc(result_size * sizeof(char *));
  for (int i = 0; i < numsSize; i++) {
    if (nums[i] != end) {
      if (start != (end - 1))
        rng = make_range(start, end - 1, true);
      else
        rng = make_range(start, -1, false);
      // Add range, after checking we have enough space.
      MAYBE_REALLOC(result, num_ranges, result_size)
      result[num_ranges++] = rng;
      start = nums[i];
      end = start;
    }
    end++;
  }
  // Finished with a solo number.
  rng = NULL;
  if (start == nums[numsSize - 1]) {
    rng = make_range(start, -1, false);
  }
  // Finished in a range.
  else if (start != (end - 1)) {
    rng = make_range(start, end - 1, true);
  }
  if (rng) {
    // Add range, after checking we have enough space.
    MAYBE_REALLOC(result, num_ranges, result_size)
    result[num_ranges++] = rng;
  }
  // Set return size and return.
  *returnSize = num_ranges;
  return result;
}