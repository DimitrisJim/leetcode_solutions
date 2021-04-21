/**
 * @param {number} maxSize
 */
var CustomStack = function(maxSize) {
  this.storage = [];
  this.maxSize = maxSize;
};

/**
 * @param {number} x
 * @return {void}
 */
CustomStack.prototype.push = function(x) {
  if (this.storage.length < this.maxSize) this.storage.push(x);
};

/**
 * @return {number}
 */
CustomStack.prototype.pop = function() {
  if (this.storage.length > 0) return this.storage.pop();
  return -1;
};

/**
 * @param {number} k
 * @param {number} val
 * @return {void}
 */
CustomStack.prototype.increment = function(k, val) {
  const limit = Math.min(k, this.storage.length);
  for (let i = 0; i < limit; i++) this.storage[i] += val;
};