/**
 * @param {number[]} nums
 * @param {number} val
 * @return {number}
 */
let removeElement = (nums, val) => {
  let start = 0, finish = nums.length;
  while (start < finish) {
    if (nums[start] == val) {
      // remove end element and replace if
      // there's still space.
      let end = nums.pop();
      finish--;
      if (start < finish) {
        nums[start] = end;
      }
    } else {
      start++;
    }
  }
  return finish;
};