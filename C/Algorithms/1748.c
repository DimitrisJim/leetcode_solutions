/*
See answer here:
        - https://stackoverflow.com/a/24753227

not including code due to license conflict. Basically verbatim with
only change being that left shifts of `1` in putbit have been cast
to uint32_t with UINT32_C before hand (a value of 31 result in 1
being shifter left by 31 which is a runtime error.)
*/
#define MAX_NUM_SIZE 100

int sumOfUnique(int *nums, int numsSize) {
  // Initialize two zero'ed bitarrays.
  bitarray_t seen[RESERVE_BITS(MAX_NUM_SIZE)] = {0};
  bitarray_t unique[RESERVE_BITS(MAX_NUM_SIZE)] = {0};

  for (int i = 0; i < numsSize; i++) {
    uint32_t value = nums[i];
    int b = getbit(seen, value);
    if (b) {
      b = getbit(unique, value);
      if (b) {
        putbit(unique, value, 0);
      }
    } else {
      putbit(unique, value, 1);
      putbit(seen, value, 1);
    }
  }

  int s = 0;
  for (int i = 1; i <= MAX_NUM_SIZE; i++) {
    if (getbit(unique, i))
      s += i;
  }
  return s;
}
