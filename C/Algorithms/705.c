#include <stdbool.h>
#include <stdlib.h>

// Uses linear probing, lazy deletion.
#define LOAD_FACTOR 0.73
// Step along linearly (1, 2, 3, ..., n)
#define PROBE_LINEAR(value, step, size) (hash_int(value) + (step)) % size;

// Helper types.

// Structure for slots the set holds.
// Try and reduce memory. With values:
// 'f' -> free.
// 'o' -> occupied.
// 'd' -> deleted.
typedef struct {
  unsigned char type;
  unsigned value;
} slot;

typedef struct {
  slot *storage;
  unsigned size;
  unsigned length;
} MyHashSet;
typedef MyHashSet set;

// Prototypes.
unsigned next_prime(unsigned);
unsigned int hash_int(unsigned int);
unsigned probe_linear(int, unsigned, unsigned);

set *setCreateWithSize(unsigned);
set *myHashSetCreate();
void resizeSetStorage(set *);
void myHashSetAdd(set *, int);
void myHashSetRemove(set *, int);
void myHashSetFree(set *);
bool myHashSetContains(set *, int);

// Constants, implementation.
const int PRIMES_SIZE = 9;
static int primes[] = {23, 101, 311, 619, 1249, 2251, 4651, 6278, 10639};

unsigned next_prime(unsigned prime) {
  for (int i = 0; i < PRIMES_SIZE; i++) {
    if (prime < primes[i])
      return primes[i];
  }
  // By problem statement, this should only
  // occur if # of adds is a bit over 7000.
  return 17291;
}

// Thanks: https://stackoverflow.com/a/12996028
// Todo: Try removing second mult by magic number, see
// how it affects performance. (Update: seems worse.)
inline unsigned int hash_int(unsigned int x) {
  x = ((x >> 16) ^ x) * 0x45d9f3b;
  x = ((x >> 16) ^ x) * 0x45d9f3b;
  x = (x >> 16) ^ x;
  return x;
}

// Create a new set using `size` as the size.
set *setCreateWithSize(unsigned size) {
  set *s = malloc(sizeof(*s));
  // realloc storage, update struct members.
  s->size = next_prime(size);
  s->length = 0;
  s->storage = malloc(s->size * sizeof(s->storage[0]));

  // Initialize storage to signify that everything is empty:
  slot *st = s->storage;
  int ssize = s->size;
  for (int i = 0; i < ssize; i++) {
    st[i].type = 'f';
  }
  return s;
}

// Initialization with smallest size.
set *myHashSetCreate() { return setCreateWithSize(0); }

// Resize the underlying storage by creating a temporary set, adding all
// occupied slots to it and then switching the storages around.
void resizeSetStorage(set *s) {
  unsigned size = next_prime(s->size);
  set *tmp = setCreateWithSize(size);

  // printf("Resizing to %d..\n", size);
  slot *tmpst = s->storage;
  int ssize = s->size;
  for (int i = 0; i < ssize; i++) {
    if (tmpst[i].type == 'o') {
      myHashSetAdd(tmp, tmpst[i].value);
    }
  }

  // Copy from tmp to s:
  s->size = tmp->size;
  s->length = tmp->length;

  // Switch storages and free.
  s->storage = tmp->storage;
  tmp->storage = tmpst;
  myHashSetFree(tmp);
}

void myHashSetAdd(set *s, int key) {
  unsigned size = s->size, step = 0;
  slot *st = s->storage;
  while (1) {
    unsigned index = PROBE_LINEAR(key, step++, size);
    slot slt = st[index];
    switch (slt.type) {
    // Case 'f', drop into 'd'.
    case 'f':
    case 'd': {
      st[index] = (slot){'o', key};
      s->length++;
      if (((float)s->length / size) >= LOAD_FACTOR) {
        resizeSetStorage(s);
      }
      return;
    }
    // Return if we find it, else continue.
    case 'o': {
      if (slt.value == key)
        return;
      break;
    }
    }
  }
}

void myHashSetRemove(set *s, int key) {
  unsigned size = s->size, step = 0;
  slot *st = s->storage;
  while (1) {
    unsigned index = PROBE_LINEAR(key, step++, size);
    slot slt = st[index];
    switch (slt.type) {
    // Not in here.
    case 'f':
      return;
    // If found, mark as 'd' and return.
    case 'o': {
      if (slt.value == key) {
        st[index].type = 'd';
        s->length--;
        return;
      }
      // else, keep looking along probe chain.
      continue;
    }
      // Do not care about case 'd'.
    }
  }
}

/** Returns true if this set contains the specified element */
bool myHashSetContains(set *s, int key) {
  unsigned size = s->size, step = 0;
  int ilast_deleted = -1;
  slot *st = s->storage;

  while (1) {
    unsigned index = PROBE_LINEAR(key, step++, size);
    slot slt = st[index];
    switch (slt.type) {
    case 'f':
      return false;
    case 'o': {
      if (slt.value == key) {
        if (ilast_deleted != -1) {
          // Move to position of last deleted in probe chain.
          st[ilast_deleted] = (slot){'o', slt.value};
          st[index].type = 'f';
        }
        return true;
      }
      // else, keep looking along probe chain.
      break;
    }
    case 'd':
      ilast_deleted = index;
      break;
    }
  }
  return false;
}

void myHashSetFree(set *s) {
  if (s) {
    free(s->storage);
    free(s);
  }
}
