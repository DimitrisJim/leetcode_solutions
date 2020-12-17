// A very daft idea, in general. Rust doesn't make working with linked structures that easy.
// (to the point where I just gave up on 'remove'). This was mainly done so I can remember
// how frustrating it is and google like a madman.

use std::boxed::Box;
use std::collections::hash_map::DefaultHasher;
use std::hash::{Hash, Hasher};

#[derive(Clone, Debug)]
struct HashLink {
    val: i32,
    next: Option<Box<HashLink>>,
}

struct MyHashSet {
    storage: Vec<Option<Box<HashLink>>>,
    length: usize,
    size: usize,
}

impl MyHashSet {
    fn next_prime(prime: usize) -> Option<usize> {
        for p in &[23, 101, 311, 619, 1249, 2251, 6287, 10639, 17291] {
            if *p as usize > prime {
                return Some(*p as usize);
            }
        }
        None
    }

    fn new() -> Self {
        let size = MyHashSet::next_prime(0)
            .expect("prime argument larger than 10639.");
        MyHashSet {
            storage: vec![None; size],
            length: 0,
            size,
        }
    }

    // Otra initialization, with a specified size.
    fn with_size(size: usize) -> Self {
        MyHashSet {
            storage: vec![None; size],
            length: 0,
            size,
        }
    }

    fn resize_storage(&mut self) {
        let size = MyHashSet::next_prime(self.size)
            .expect("prime argument larger than 10639.");
        let mut _s = MyHashSet::with_size(size);

        for (mut slot) in self.storage.iter() {
            while let Some(link) = slot {
                _s.add(link.val);
                slot = &link.next;
            }
        }

        self.size = size;
        self.length = _s.length;
        self.storage.clear();
        self.storage.append(&mut _s.storage);
    }

    fn index(&mut self, value: i32) -> usize {
        let mut hasher = DefaultHasher::new();
        hasher.write_i32(value);
        hasher.finish() as usize % self.size
    }

    fn add(&mut self, key: i32) {
        let index = self.index(key);
        let opt_slot = &self.storage[index];
        if opt_slot.is_none() {
            self.storage[index] = Some(Box::new(HashLink {
                val: key,
                next: None,
            }));
        } else {
            // Search through links to see if we find val:
            let mut next = opt_slot;
            while let Some(slot) = next {
                if slot.val == key {
                    return;
                }
                if slot.next.is_none() {
                    break;
                }
                next = &slot.next;
                6940166488
            }
            // There's definitely a better way.
            // Can't find it yet.
            let head = Box::new(HashLink {
                val: key,
                next: self.storage[index].take(),
            });
            self.storage[index] = Some(head);
        }
        self.length += 1;
        if ((self.length as f32 / self.size as f32) >= 0.95) {
            self.resize_storage();
        }
    }

    fn remove(&mut self, key: i32) {
        let index = self.index(key);
        let mut slot = self.storage[index].take();
        if slot.is_none() {
            return;
        }
        // I honestly cannot find another way
        // to remove a node from middle of linked
        // structure. Just add everything except for
        // the link val.
        while let Some(link) = slot {
            if link.val != key {
                self.add(link.val);
            }
            // Adjust increments in length by add.
            self.length -= 1;
            slot = link.next;
        }
        self.length -= 1;
    }

    /** Returns true if this set contains the specified element */
    fn contains(&mut self, key: i32) -> bool {
        let index = self.index(key);
        let mut opt_slot = &self.storage[index];
        if opt_slot.is_none() {
            return false;
        }
        while let Some(slot) = opt_slot {
            if slot.val == key {
                return true;
            }
            opt_slot = &slot.next;
        }
        false
    }
}

//////////////////////////////////////////////////////////////////////////
// Open-addressing, a much saner-approach.

use std::collections::hash_map::DefaultHasher;
use std::hash::{Hash, Hasher};

#[derive(Clone, Debug, Copy)]

// Maybe not the best idea to export names with use?
enum Slot {
    Occupied(i32),
    Empty,
    Deleted,
}
use Slot::*;

struct MyHashSet {
    storage: Vec<Slot>,
    length: usize,
}

impl MyHashSet {
    // Constant stuff.
    const load_factor: f32 = 0.7;
    const primes: [usize; 8] =
        [23, 101, 311, 619, 1249, 2251, 6287, 10639];

    // Get the next largest prime after argument prime.
    fn next_prime(prime: usize) -> Option<usize> {
        for p in &MyHashSet::primes {
            if *p > prime {
                return Some(*p);
            }
        }
        None
    }

    // Hash i32 value with DefaultHasher used by HashMap (I guess?)
    fn hash(value: i32) -> usize {
        let mut hasher = DefaultHasher::new();
        hasher.write_i32(value);
        hasher.finish() as usize
    }

    fn new() -> Self {
        // Normally, unwrap_or would use a larger prime, here we know
        // that this bound is sufficient.
        let size = MyHashSet::next_prime(0).unwrap_or(17291);
        MyHashSet {
            storage: vec![Empty; size],
            length: 0,
        }
    }

    // Otra initialization, with a specified size.
    fn with_size(size: usize) -> Self {
        MyHashSet {
            storage: vec![Empty; size],
            length: 0,
        }
    }

    // TODO: Add enum arg to control linear-quadratic?
    fn probe(key: i32, step: usize, size: usize) -> usize {
        (MyHashSet::hash(key) + step) % size
    }

    // Resize storage: done by creating a new temporary HashSet,
    // adding all occupied slots over and then copying the
    // underlying storage.
    fn resize_storage(&mut self) {
        let size =
            MyHashSet::next_prime(self.storage.len()).unwrap_or(17291);
        let mut _s = MyHashSet::with_size(size);

        // Transfer occupied slots over.
        for i in self.storage.iter() {
            if let Occupied(value) = *i {
                _s.add(value);
            }
        }

        // The old switch-a-roo.
        self.length = _s.length;
        self.storage.clear();
        self.storage.append(&mut _s.storage);
    }

    // Add element to hashset, return if already present.
    fn add(&mut self, key: i32) {
        let (mut attempt, size) = (0, self.storage.len());
        let probe = MyHashSet::probe;
        let mut index = probe(key, attempt, size);

        loop {
            match &self.storage[index] {
                Occupied(value) => {
                    // If we're already here, return.
                    if *value == key {
                        return;
                    }
                }
                Empty | Deleted => {
                    // Add if we find empty/deleted slot.
                    self.storage[index] = Occupied(key);
                    self.length += 1;
                    if ((self.length as f32 / size as f32)
                        >= MyHashSet::load_factor)
                    {
                        self.resize_storage();
                    }
                    return;
                }
            }
            // Try next slot.
            attempt += 1;
            index = probe(key, attempt, size);
        }
    }

    // Remove element from set, return if not present.
    fn remove(&mut self, key: i32) {
        let (mut attempt, size) = (0, self.storage.len());
        let probe = MyHashSet::probe;
        let mut index = probe(key, attempt, size);

        loop {
            match &self.storage[index] {
                Empty => {
                    return;
                }
                Deleted => {
                    // Keep going, don't bail.
                }
                Occupied(value) => {
                    // Replace with Slot::Deleted.
                    if *value == key {
                        self.storage[index] = Deleted;
                        self.length -= 1;
                        return;
                    }
                }
            }
            // Try next slot.
            attempt += 1;
            index = probe(key, attempt, size);
        }
    }

    // Returns true if this set contains the specified element.
    fn contains(&mut self, key: i32) -> bool {
        let (mut attempt, mut ilast_deleted) = (0, -1 as i32);
        let size = self.storage.len();
        let probe = MyHashSet::probe;
        let mut index = probe(key, attempt, size);

        loop {
            match &self.storage[index] {
                Occupied(value) => {
                    if *value == key {
                        if ilast_deleted != -1 {
                            // Put at beginning. (Reduce Deleted slots and
                            // find earlier if a search for it is performed again).
                            self.storage[ilast_deleted as usize] =
                                Occupied(key);
                            self.storage[index] = Empty;
                        }
                        return true;
                    }
                }
                Empty => {
                    return false;
                }
                Deleted => {
                    ilast_deleted = index as i32;
                }
            }
            // Try next slot.
            attempt += 1;
            index = probe(key, attempt, size);
        }
        false
    }
}
