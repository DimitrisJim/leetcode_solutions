#include <pthread.h>

typedef struct {
  unsigned turn;
  pthread_cond_t cv;
  pthread_mutex_t turn_lock;
} Foo;

Foo *fooCreate() {
  Foo *obj = (Foo *)malloc(sizeof(Foo));

  // yes, I do not check returns.
  obj->turn = 1;
  pthread_mutex_init(&obj->turn_lock, NULL);
  pthread_cond_init(&obj->cv, NULL);
  return obj;
}

void first(Foo *obj) {
  pthread_cond_t *cv = &obj->cv;
  pthread_mutex_t *turn_lock = &obj->turn_lock;

  // Acquire lock, invoke printFirst and increment turn; broadcast to the
  // rest of the threads possibly waiting to wake up and check the turn.
  // Unlock and finish. Does not wait.
  pthread_mutex_lock(turn_lock);
  printFirst();
  obj->turn++;

  // Signal others to wake-up.
  pthread_cond_broadcast(cv);
  pthread_mutex_unlock(turn_lock);
}

void second(Foo *obj) {
  pthread_cond_t *cv = &obj->cv;
  pthread_mutex_t *turn_lock = &obj->turn_lock;

  // Acquire lock, invoke printSecond and increment turn; use signal since
  // we now only third will possibly be waiting. Release lock.
  // Waits until turn is 2.
  pthread_mutex_lock(turn_lock);

  while (obj->turn != 2)
    pthread_cond_wait(cv, turn_lock);
  printSecond();
  obj->turn++;

  // Signal third to wake-up.
  pthread_cond_signal(cv);
  pthread_mutex_unlock(turn_lock);
}

void third(Foo *obj) {
  pthread_cond_t *cv = &obj->cv;
  pthread_mutex_t *turn_lock = &obj->turn_lock;

  // Acquire lock, invoke printThird and return. Waits until turn is 3.
  pthread_mutex_lock(turn_lock);

  while (obj->turn != 3)
    pthread_cond_wait(cv, turn_lock);
  printThird();

  pthread_mutex_unlock(turn_lock);
}

void fooFree(Foo *obj) {
  // User defined data may be cleaned up here.
  pthread_mutex_destroy(&obj->turn_lock);
  pthread_cond_destroy(&obj->cv);
}