typedef struct {
  int *storage;
  int size;
  int maxSize;
} CustomStack;

CustomStack *customStackCreate(int maxSize) {
  CustomStack *s = malloc(sizeof(*s));

  s->storage = malloc(maxSize * sizeof(int));
  s->size = 0;
  s->maxSize = maxSize;

  return s;
}

void customStackPush(CustomStack *obj, int x) {
  if (obj->size < obj->maxSize)
    obj->storage[obj->size++] = x;
}

int customStackPop(CustomStack *obj) {
  if (obj->size > 0)
    return obj->storage[--obj->size];
  return -1;
}

void customStackIncrement(CustomStack *obj, int k, int val) {
  int limit = k < obj->size ? k : obj->size;
  for (int i = 0; i < limit; i++)
    obj->storage[i] += val;
}

void customStackFree(CustomStack *obj) {
  if (obj) {
    free(obj->storage);
    free(obj);
  }
}