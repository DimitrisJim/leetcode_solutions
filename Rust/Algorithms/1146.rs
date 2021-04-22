use std::collections::HashMap;

struct SnapshotArray {
    storage: Vec<HashMap<i32, i32>>,
    snap_id: i32,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl SnapshotArray {
    fn new(length: i32) -> Self {
        // Build a map 0 -> 0 for each entry.
        let m: HashMap<_, _> = [(0, 0)].iter().cloned().collect();
        let storage: Vec<_> =
            (0..length).map(|_| m.clone()).collect();

        Self {
            storage,
            snap_id: 0,
        }
    }

    fn set(&mut self, index: i32, val: i32) {
        self.storage[index as usize].insert(self.snap_id, val);
    }

    fn snap(&mut self) -> i32 {
        self.snap_id += 1;
        self.snap_id - 1
    }

    fn get(&self, index: i32, snap_id: i32) -> i32 {
        let snapshots = &self.storage[index as usize];
        
        // If a key exists for given snap_id, directly return contents.
        if let Some(&value) = snapshots.get(&snap_id) {
            return value;
        }
        
        // Else, go through keys of snapshots and get largest key 
        // that's smaller than snap_id.
        match snapshots
            .keys()
            .filter(|&&snapshot| snapshot < snap_id)
            .min_by_key(|&&snapshot| snap_id - snapshot)
        {
            Some(snapshot) => snapshots.get(snapshot).cloned().unwrap(),
            // *should never hit*, we initialize each slot with a map that
            // has a key of `0`.
            None => panic!(),
        }
    }
}
