/**
 * Initialize your data structure here. Set the size of the deque to be k.
 * @param {number} k
 */
var MyCircularDeque = function(k) {
  this.values = Array(k);
  this.num_elements = 0;
  this.front = 0;
};

/**
 * Adds an item at the front of Deque. Return true if the operation is
 * successful.
 * @param {number} value
 * @return {boolean}
 */
MyCircularDeque.prototype.insertFront = function(value) {
  if (this.isFull()) return false;

  let st = this.values
           // new position of front will be front - 1 mod the size of deque.
           this.front = (this.front + st.length - 1) % st.length;
  st[this.front] = value;
  this.num_elements++;
  return true;
};

/**
 * Adds an item at the rear of Deque. Return true if the operation is
 * successful.
 * @param {number} value
 * @return {boolean}
 */
MyCircularDeque.prototype.insertLast = function(value) {
  if (this.isFull()) return false;

  // End (tail) is going to be front + length mod size of deque
  let back = (this.front + this.num_elements) % this.values.length;
  this.values[back] = value;
  this.num_elements++;
  return true;
};

/**
 * Deletes an item from the front of Deque. Return true if the operation is
 * successful.
 * @return {boolean}
 */
MyCircularDeque.prototype.deleteFront = function() {
  if (this.isEmpty()) return false;

  // to delete, just advance front by one mod size.
  this.front = (this.front + 1) % this.values.length;
  this.num_elements--;
  return true;
};

/**
 * Deletes an item from the rear of Deque. Return true if the operation is
 * successful.
 * @return {boolean}
 */
MyCircularDeque.prototype.deleteLast = function() {
  if (this.isEmpty()) return false;

  // affects get/insert{rear} which depend on it.
  this.num_elements--;
  return true;
};

/**
 * Get the front item from the deque.
 * @return {number}
 */
MyCircularDeque.prototype.getFront = function() {
  if (this.isEmpty()) return -1;
  return this.values[this.front]
};

/**
 * Get the last item from the deque.
 * @return {number}
 */
MyCircularDeque.prototype.getRear = function() {
  if (this.isEmpty()) return -1;

  // Calculate end based on front and length mod size. Note that
  // front + length denotes empty position in which we could insert
  // (see insertBack), this is why we decrement it by one.
  size = this.values.length;
  return this.values[(this.front + this.num_elements - 1) % size];
};

/**
 * Checks whether the circular deque is empty or not.
 * @return {boolean}
 */
MyCircularDeque.prototype.isEmpty = function() {
  return this.num_elements == 0;
};

/**
 * Checks whether the circular deque is full or not.
 * @return {boolean}
 */
MyCircularDeque.prototype.isFull = function() {
  return this.num_elements == this.values.length;
};
