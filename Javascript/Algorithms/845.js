/**
 * @param {number[]} arr
 * @return {number}
 */
var longestMountain = function(arr) {
  let i = 0, max = 0, end = arr.length - 1;
  while (i < end) {
    let up = 1, k = i;
    while (k < end && arr[k] < arr[k + 1]) {
      up++;
      k++;
    }
    // Start looking for a way down if we've found a
    // way up.
    if (up > 1) {
      let down = 0;
      while (k < end && arr[k] > arr[k + 1]) {
        down++;
        k++;
      }
      // must have both down and up to have a mountain.
      if (down) {
          max = Math.max(max, up + down);
          i += down - 1;
      }
    }
    // start looking again after the peak (if none were found
    // this will be == 1)
    i += up;
  }
  return max;
};