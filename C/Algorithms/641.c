typedef struct {
  int *values;
  int front;
  int size;
  int length;
} MyCircularDeque;

/** Initialize your data structure here. Set the size of the deque to be k. */
MyCircularDeque *myCircularDequeCreate(int k) {
  MyCircularDeque *d = malloc(sizeof(*d));
  d->values = malloc(k * sizeof(int));
  d->size = k;
  d->front = d->length = 0;
  return d;
}

/** Checks whether the circular deque is empty or not. */
bool myCircularDequeIsEmpty(MyCircularDeque *obj) { return obj->length == 0; }

/** Checks whether the circular deque is full or not. */
bool myCircularDequeIsFull(MyCircularDeque *obj) {
  if (obj->length == obj->size)
    return true;
  return false;
}

/** Adds an item at the front of Deque. Return true if the operation is
 * successful. */
bool myCircularDequeInsertFront(MyCircularDeque *obj, int value) {
  if (myCircularDequeIsFull(obj))
    return false;

  // (-1 % 3) == -1 ? that's why I add obj->size here.
  // new position of front will be front - 1 mod the size of deque.
  obj->front = (obj->front + obj->size - 1) % obj->size;
  obj->values[obj->front] = value;
  obj->length++;
  return true;
}

/** Adds an item at the rear of Deque. Return true if the operation is
 * successful. */
bool myCircularDequeInsertLast(MyCircularDeque *obj, int value) {
  if (myCircularDequeIsFull(obj))
    return false;

  // End (tail) is going to be front + length mod size of deque.
  int end = (obj->front + obj->length) % obj->size;
  obj->values[end] = value;
  obj->length++;
  return true;
}

/** Deletes an item from the front of Deque. Return true if the operation is
 * successful. */
bool myCircularDequeDeleteFront(MyCircularDeque *obj) {
  if (myCircularDequeIsEmpty(obj))
    return false;

  // to delete, just advance front by one mod size.
  obj->front = (obj->front + 1) % obj->size;
  obj->length--;
  return true;
}

/** Deletes an item from the rear of Deque. Return true if the operation is
 * successful. */
bool myCircularDequeDeleteLast(MyCircularDeque *obj) {
  if (myCircularDequeIsEmpty(obj))
    return false;

  // Decrementing length essentially makes a get (or insert) reach
  // the previous index in the array (since end in those functions
  // is calculated based on the length.)
  obj->length--;
  return true;
}

/** Get the front item from the deque. */
int myCircularDequeGetFront(MyCircularDeque *obj) {
  if (myCircularDequeIsEmpty(obj))
    return -1;
  return obj->values[obj->front];
}

/** Get the last item from the deque. */
int myCircularDequeGetRear(MyCircularDeque *obj) {
  if (myCircularDequeIsEmpty(obj))
    return -1;

  // Calculate end based on front and length mod size. Note that
  // front + length denotes empty position in which we could insert
  // (see insertBack), this is why we decrement it by one.
  return obj->values[(obj->front + obj->length - 1) % obj->size];
}

void myCircularDequeFree(MyCircularDeque *obj) {
  if (obj) {
    free(obj->values);
    free(obj);
  }
}