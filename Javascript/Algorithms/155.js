var MinStack = function() {
    this.min = null;
    this.stack = [];
};

/** 
 * Push value into MinStack.
 * @param {number} x
 * @return {void}
 *
 * Amortized O(1) due to stack.push. Min is checked to
 * see if value pushed is smaller (and if so, it's kept.)
 */
MinStack.prototype.push = function(x) {
    this.stack.push(x);
    if (this.min == null || this.min > x)
        this.min = x;
};

/**
 * Pop a value from the MinStack.
 * @return {void}
 *
 * O(N) due search for min. Value popped is checked to
 * see if it is equal to min, if so, a new min must be found.
 */
MinStack.prototype.pop = function() {
    let stack = this.stack;
    if (stack.pop() == this.min) {
        if (stack.length == 0)
            this.min = null;
        else {
            let min = stack[0];
            stack.forEach(x => {
                if (x < min)
                    min = x;
            });
            this.min = min;
        }
    }
};

/**
 * Return the TOS.
 * @return {number}
 *
 * O(1), list indexing.
 */
MinStack.prototype.top = function() {
    return this.stack[this.stack.length-1];
};

/**
 * Return min.
 * @return {number}
 *
 * O(1), simple attribute access.
 */
MinStack.prototype.getMin = function() {
    return this.min;
};
