use std::collections::HashMap;

struct OrderedStream {
    ptr: i32,
    values: HashMap<i32, String>,
}

impl OrderedStream {
    fn new(n: i32) -> Self {
        OrderedStream {
            ptr: 1,
            values: HashMap::with_capacity(n as usize),
        }
    }

    fn insert(&mut self, id: i32, value: String) -> Vec<String> {
        let mut res = Vec::new();
        self.values.insert(id, value);
        while let Some(value) = self.values.remove(&self.ptr) {
            res.push(value);
            self.ptr += 1;
        }
        res
    }
}
