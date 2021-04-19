/**
 * @param {number[]} nums
 */
var Solution = function(nums) {
  this.original = nums;
};

/**
 * Resets the array to its original configuration and return it.
 * @return {number[]}
 */
Solution.prototype.reset = function() {
  return this.original;
};

/**
 * Returns a random shuffling of the array.
 * @return {number[]}
 */
Solution.prototype.shuffle = function() {
  const randInt = (start, end) => {
    // exclusive end.
    return Math.floor(start + (Math.random() * (end - start)))
  };
  let result = [...this.original];
  for (let i = 0; i < result.length - 1; i++) {
    let j = randInt(i, result.length)
    let tmp = result[i];
    result[i] = result[j];
    result[j] = tmp;
  }
  return result;
};