use std::cmp::min;

struct CustomStack {
    storage: Vec<i32>,
    maxSize: usize,
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl CustomStack {

    fn new(maxSize: i32) -> Self {
        let maxSize = maxSize as usize;
        Self { storage: Vec::with_capacity(maxSize), maxSize }
    }
    
    fn push(&mut self, x: i32) {
        if self.storage.len() < self.maxSize {
            self.storage.push(x);
        }
    }
    
    fn pop(&mut self) -> i32 {
        match self.storage.len() {
            0 => -1,
            _ => self.storage.pop().unwrap(),
        }
    }
    
    fn increment(&mut self, k: i32, val: i32) {
        for i in 0..min(k as usize, self.storage.len()) {
            self.storage[i] += val;
        }
    }
}