// Linear probing and lazy deletion.
// Use null to signify empty slot and undefined to signify deleted.

// Thanks: https://stackoverflow.com/a/12996028
// Todo: Try removing second mult by magic number, see
// how it affects performance. (Update: seems worse.)
const hash_int = x => {
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = (x >> 16) ^ x;
    return x;
}
// Step along linearly (1, 2, 3, ..., n)
const probe_linear = (value, step, size) => (hash_int(value) + (step)) % size;
const primes = [23, 101, 311, 619, 1249, 2251, 4651, 6278, 10639];
const load_factor = 0.75;

const next_prime = prime => {
    for(let i = 0; i < primes.length; i++){
        if (prime < primes[i])
            return primes[i];
    }
    // By problem statement, this should only 
    // occur if # of adds is a bit over 7000.
    return 17291;
}

/**
 * Initialize your data structure here.
 */
var MyHashSet = function(size=0) {
    let set_size = next_prime(size);
    this.length = 0;
    this.size = set_size;
    this.storage = Array(set_size);
    
    // Can use null's and undefined's
    for (let i = 0; i < set_size; i++){
        this.storage[i] = null;
    }
};

MyHashSet.prototype.resize = function(size) {
    let new_size = next_prime(size);
    let temp = new MyHashSet(new_size);
    
    // Add over.
    const storage = this.storage
    for (let i = 0; i < new_size; i++){
       if (storage[i] != null && storage[i] != undefined){
           temp.add(storage[i]);
       }
    }
    // Switch:
    this.size = new_size;
    this.storage = temp.storage;
    temp.storage = storage;
    console.log("Resized to: ", this.size);
}

/** 
 * @param {number} key
 * @return {void}
 */
MyHashSet.prototype.add = function(key) {
    const size = this.size,
          st = this.storage;
    let step = 0;

    while (1) {
        let index = probe_linear(key, step++, size);
        let slot = st[index];
        if (slot == key){
            return;
        }
        // Add if we find empty/deleted slot.
        if (slot == undefined || slot == null){
            st[index] = key;
            this.length++;
            // resize if necessary:
            if ((this.length / size) >= load_factor){
                this.resize(size);
            }
            return;
        }
    }
};

/** 
 * @param {number} key
 * @return {void}
 */
MyHashSet.prototype.remove = function(key) {
    const size = this.size,
          st = this.storage;
    let step = 0;

    while (1) {
        let index = probe_linear(key, step++, size);
        let slot = st[index];
        // Add if we find empty/deleted slot.
        if (slot == null){ 
            return;
        }
        if (slot == key){
            st[index] = undefined;
            this.length--;
            return;
        }
    }
};

/**
 * Returns true if this set contains the specified element 
 * @param {number} key
 * @return {boolean}
 */
MyHashSet.prototype.contains = function(key) {
    const size = this.size,
          st = this.storage;
    let step = 0,
        ilast_deleted = -1;
    
    while (1) {
        let index = probe_linear(key, step++, size);
        let slot = st[index];
        if (slot == key){
            if (ilast_deleted != -1){
                st[ilast_deleted] = key;
                st[index] = null;
            }
            return true;
        }
        
        if (slot == null){ 
            return false;
        }
        if (slot == undefined){
            ilast_deleted = index;
        }
    }
};
