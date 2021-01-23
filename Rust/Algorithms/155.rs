struct MinStack {
    min: Option<i32>,
    stack: Vec<i32>,
}

impl MinStack {
    /** initialize your data structure here. */
    fn new() -> Self {
        Self {
            min: None,
            stack: vec![],
        }
    }

    /** Push x into stack.

    We update min if value added is smaller. Amortized O(1) due to
    stack.push.
    */
    fn push(&mut self, x: i32) {
        self.stack.push(x);
        let v = Some(x);
        if self.min.is_none() || self.min > v {
            self.min = v;
        }
    }

    /** Pop from the stack.

    We update min if value poped is equal to min to the new min in stack.
    O(N) due to min.
    */
    fn pop(&mut self) {
        if self.stack.pop() == self.min {
            // Go from Option<&T> to Option<T>
            self.min = self.stack.iter().min().cloned();
        }
    }

    /** Return TOS.

    O(1) since `.last()` is O(1) operation.
    */
    fn top(&self) -> i32 {
        // Requirements state we call top on non-empty stack.
        self.stack[self.stack.len() - 1]
    }

    /** Return min.

    O(1) - simple attribute access.
    */
    fn get_min(&self) -> i32 {
        self.min.unwrap()
    }
}
