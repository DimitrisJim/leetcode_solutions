var SnapshotArray = function(length) {
  const storage = [], initializer = [[0, 0]];
  for (let i = 0; i < length; i++) {
    storage.push(new Map(initializer));
  }
  this.storage = storage;
  this.snap_id = 0;
};

SnapshotArray.prototype.set = function(index, val) {
  this.storage[index].set(this.snap_id, val);
};

SnapshotArray.prototype.snap = function() {
  this.snap_id++;
  return this.snap_id - 1;
};

SnapshotArray.prototype.get = function(index, snap_id) {
  const map = this.storage[index], f = x => x < snap_id;
  // If it's already set, just return the value associated.
  return map.has(snap_id) ? map.get(snap_id) :
                            map.get(Math.max(...[...map.keys()].filter(f)));
};