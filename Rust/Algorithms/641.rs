struct MyCircularDeque {
    values: Vec<i32>,
    front: usize,
    length: usize,
}

impl MyCircularDeque {
    /** Initialize your data structure here. Set the size of the deque to be k. */
    fn new(k: i32) -> Self {
        Self {
            values: vec![0; k as usize],
            front: 0,
            length: 0,
        }
    }

    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    fn insert_front(&mut self, value: i32) -> bool {
        if self.is_full() {
            return false;
        }

        self.front =
            (self.front + self.values.len() - 1) % self.values.len();
        self.values[self.front] = value;
        self.length += 1;

        true
    }

    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    fn insert_last(&mut self, value: i32) -> bool {
        if self.is_full() {
            return false;
        }

        let len = self.values.len();
        self.values[(self.front + self.length) % len] = value;
        self.length += 1;

        true
    }

    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    fn delete_front(&mut self) -> bool {
        if self.is_empty() {
            return false;
        }
        // to delete front, just advance front by one mod size of vec holding values.
        self.front = (self.front + 1) % self.values.len();

        self.length -= 1;
        true
    }

    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    fn delete_last(&mut self) -> bool {
        if self.is_empty() {
            return false;
        }
        // last depends on number of elements inserted. by decrementing it here
        // we affect look-ups in the other functions. (get/insert)
        self.length -= 1;
        true
    }

    /** Get the front item from the deque. */
    fn get_front(&self) -> i32 {
        if self.is_empty() {
            return -1;
        }
        self.values[self.front]
    }

    /** Get the last item from the deque. */
    fn get_rear(&self) -> i32 {
        if self.is_empty() {
            return -1;
        }
        // rear is going to be front + length - 1 mod size of values vec.
        // -1 brings us in the position holding the value. front + length,
        // on their own, denote position in which it is possible to insert
        // (see insert_rear).
        self.values[(self.front + self.length - 1) % self.values.len()]
    }

    /** Checks whether the circular deque is empty or not. */
    fn is_empty(&self) -> bool {
        self.length == 0
    }

    /** Checks whether the circular deque is full or not. */
    fn is_full(&self) -> bool {
        self.values.len() == self.length
    }
}
