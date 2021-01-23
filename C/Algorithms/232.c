#include <stdbool.h>
#include <stdlib.h>

typedef struct {
  int *storage, *tmp;
  int storageSize, storageLength;
  int tmpSize, tmpLength;
} MyQueue;

/** Transfer elements from storage to tmp in order to bring them to correct

FIFO order when needing to pop from tmp.
*/
void _qTransfer(MyQueue *q) {
  if (q->tmpLength == 0) {
    while (q->storageLength) {
      if (q->tmpLength + 1 == q->tmpSize) {
        q->tmpSize *= 1.5;
        q->tmp = realloc(q->tmp, q->tmpSize * sizeof(*q->tmp));
      }
      q->tmp[q->tmpLength++] = q->storage[--q->storageLength];
    }
  }
}

/** Initialize your data structure here. */
MyQueue *myQueueCreate() {
  // best guess init size == 10.
  MyQueue *q = malloc(sizeof(*q));
  q->storage = malloc(10 * sizeof(*q->storage));
  q->tmp = malloc(10 * sizeof(*q->tmp));

  q->storageSize = 10;
  q->tmpSize = 10;
  q->storageLength = 0;
  q->tmpLength = 0;

  return q;
}

/** Push element x to the back of queue.

Uses stack equivalent operation (basically push.)
*/
void myQueuePush(MyQueue *q, int x) {
  if (q->storageLength + 1 == q->storageSize) {
    // Need to realloc.
    q->storageSize *= 1.5;
    q->storage = realloc(q->storage, q->storageSize * sizeof(*q->storage));
  }
  // Add to storage.
  q->storage[q->storageLength++] = x;
}

/** Removes the element from in front of queue and returns that element.

First, transfer elements from storage to tmp in order to bring them to correct
FIFO order when needing to pop from tmp.

Uses stack equivalent operation for pop.
*/
int myQueuePop(MyQueue *q) {
  _qTransfer(q);
  // i.e pop.
  return q->tmp[--q->tmpLength];
}

/** Get the front element.

First, transfer elements from storage to tmp in order to bring them to correct
FIFO order when needing to peek from tmp.

Uses stack equivalent operation for peek/top.
*/
int myQueuePeek(MyQueue *q) {
  _qTransfer(q);
  return q->tmp[q->tmpLength - 1];
}

/** Returns whether the queue is empty.

Uses stack equivalent operation for is_empty (checking length.)
*/
bool myQueueEmpty(MyQueue *q) {
  return q->storageLength == 0 && q->tmpLength == 0;
}

void myQueueFree(MyQueue *q) {
  if (q) {
    free(q->storage);
    free(q->tmp);
    free(q);
  }
}
