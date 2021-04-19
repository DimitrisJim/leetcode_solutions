#include <stdlib.h>
#include <string.h>

typedef struct {
  int *nums;
  int numsLength;
} Solution;

Solution *solutionCreate(int *nums, int numsSize) {
  srand(time(NULL));
  Solution *obj = malloc(sizeof(*obj));
  obj->nums = nums;
  obj->numsLength = numsSize;

  return obj;
}

/** Resets the array to its original configuration and return it. */
int *solutionReset(Solution *obj, int *retSize) {
  *retSize = obj->numsLength;

  return obj->nums;
}

/** Returns a random shuffling of the array. */
int *solutionShuffle(Solution *obj, int *retSize) {
  int length = obj->numsLength;
  // Initialize result.
  int *result = malloc(sizeof(int) * length);
  memcpy(result, obj->nums, sizeof(int) * length);

  for (int i = 0; i < length - 1; i++) {
    // taken from C-faq.
    int idx = i + rand() / (RAND_MAX / (length - i) + 1);
    // swap elements at idx, i.
    int tmp = *(result + i);
    *(result + i) = *(result + idx);
    *(result + idx) = tmp;
  }

  *retSize = length;
  return result;
}

void solutionFree(Solution *obj) {
  // do not free nums here, I'm guessing caller does this.
  free(obj);
}