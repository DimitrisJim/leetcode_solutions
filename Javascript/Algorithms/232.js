/**
 * Initialize your data structure here.
 */
var MyQueue = function() {
    this.storage = [];
    this.tmp = [];
};

/**
 * Push element x to the back of queue. 
 * @param {number} x
 * @return {void}
 *
 * Uses stack equivalent operation push.
 */
MyQueue.prototype.push = function(x) {
    this.storage.push(x);
};

/**
 * Removes the element from in front of queue and returns that element.
 * @return {number}
 *
 * First, transfer elements over from storage to tmp to bring them in FIFO
 * order. Then we use the stack equivalent operation pop.
 */
MyQueue.prototype.pop = function() {
    this._transfer();
    return this.tmp.pop();
};

/**
 * Get the front element.
 * @return {number}
 *
 * First, transfer elements over from storage to tmp to bring them in FIFO
 * order. Then we use the stack equivalent operation for peek/top.
 */
MyQueue.prototype.peek = function() {
    this._transfer();
    return this.tmp[this.tmp.length - 1];
};

/**
 * Returns whether the queue is empty.
 * @return {boolean}
 *
 * Uses operation equivalent for is_empty.
 */
MyQueue.prototype.empty = function() {
    return this.tmp.length == 0 && this.storage.length == 0;
};

/**
 * Transfers elements from storage to tmp, uses only stack equivalent
 * operations.
 */
MyQueue.prototype._transfer = function () {
    if (this.tmp.length == 0){
        while (this.storage.length) {
            this.tmp.push(this.storage.pop());
        }
    }
}
