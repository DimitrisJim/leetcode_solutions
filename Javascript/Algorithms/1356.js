/**
 * @param {number[]} arr
 * @return {number[]}
 */
var sortByBits = (arr) => {
    arr.sort((a, b) => a - b)
	// sortBy provided by lodash.
    return _.sortBy(arr, [(i) => {
          // Similar to other files. We know i <= 10 ** 4.
          let count = 0;
          i = i - ((i >> 1) & 0x55555555);
          i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
          i = (i + (i >> 4)) & 0x0f0f0f0f;
          i = i + (i >> 8);
          i = i + (i >> 16);
          count += i & 0x3f;
          return count;
    }])
};
