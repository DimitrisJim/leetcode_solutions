struct MyQueue {
    storage: Vec<i32>,
    tmp: Vec<i32>,
}

impl MyQueue {
    /** Initialize your data structure here. */
    fn new() -> Self {
        Self {
            storage: vec![],
            tmp: vec![],
        }
    }

    /** Push element x to the back of queue.

    Uses Stack equivalent operation push (push).
    */
    fn push(&mut self, x: i32) {
        self.storage.push(x);
    }

    /** Removes the element from in front of queue and returns that element.

    Transfers elements from storage to tmp if necessary, this places elements in
    correct FIFO order. Uses only Stack equivalent operations.
    */
    fn pop(&mut self) -> i32 {
        self._transfer();
        self.tmp.pop().unwrap()
    }

    /** Get the front element.

    Transfers elements from storage to tmp if necessary, this places elements in
    correct FIFO order. Uses Stack equivalent operation last (peek, top).
    */
    fn peek(&mut self) -> i32 {
        self._transfer();
        *self.tmp.last().unwrap()
    }

    /** Returns whether the queue is empty.

    Uses stack equivalent operations len (is_empty)
    */
    fn empty(&self) -> bool {
        self.tmp.len() == 0 && self.storage.len() == 0
    }

    /** Transfer elements from storage to tmp. This uses stack equivalent
    operations len (is_empty), push (push), pop (pop).
    */
    fn _transfer(&mut self) {
        if self.tmp.len() == 0 {
            while self.storage.len() != 0 {
                self.tmp.push(self.storage.pop().unwrap());
            }
        }
    }
}
