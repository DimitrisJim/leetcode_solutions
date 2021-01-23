#include <stdlib.h>

/**
 * Pointer to memory used as set along with its length and size.
 * min and minSet in order to keep track of the min value.
 */
typedef struct {
  int *stack, min, minSet, size, length;
} MinStack;

/** initialize your data structure here. */
MinStack *minStackCreate() {
  MinStack *st = malloc(sizeof(*st));
  // Start with an initial size of 10.
  st->size = 10;
  st->length = 0;
  st->min = 0;
  // 0 -> not set, 1 -> set.
  st->minSet = 0;
  st->stack = malloc(st->size * sizeof(*st->stack));

  return st;
}

// Push item into MinStack.
// If min isn't set, or x is smaller than min, update min.
// O(1) opeation due to pushing (uses geometric increase => amortization.)
void minStackPush(MinStack *st, int x) {
  if (st->length + 1 == st->size) {
    st->size *= 1.5;
    st->stack = realloc(st->stack, st->size * sizeof(*st->stack));
  }
  st->stack[st->length++] = x;
  if (!st->minSet || st->min > x) {
    st->min = x;
    // 1 => set, 0 => unset.
    st->minSet = 1;
  }
}

// Pop item from MinStack.
// If item pop'ed is equal to min, we're removing the current min
// we're tracking. If the stack has more elements, update to new min,
// else, set minSet to zero in order for the next value pushed to be used
// as min.
// O(N) due to searching for min.
void minStackPop(MinStack *st) {
  // Guaranteed to be performed on non-empty stack.
  int x = st->stack[--(st->length)];
  if (x == st->min) {
    if (st->length == 0)
      st->minSet = 0;
    else {
      int min = st->stack[0];
      for (int i = 0; i < st->length; i++) {
        if (st->stack[i] < min)
          min = st->stack[i];
      }
      st->min = min;
    }
  }
}

// Return TOS. O(1).
int minStackTop(MinStack *st) { return st->stack[st->length - 1]; }

// Return min. O(1).
int minStackGetMin(MinStack *st) { return st->min; }

void minStackFree(MinStack *st) {
  if (st) {
    free(st->stack);
    free(st);
  }
}
