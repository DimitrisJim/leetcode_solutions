/**
 * @param {number[]} nums
 * @return {string[]}
 */
let summaryRanges = nums => {
  if (nums.length == 0) return [];

  const results = [];
  let start = nums[0], end = start;
  for (let num of nums) {
    // range ended.
    if (num != end) {
      results.push((start != (end - 1)) ? `${start}->${end - 1}` : `${start}`)
      start = end = num;
    }
    end++;
  }
  // A final number was left in nums.
  if (start == nums[nums.length - 1]) results.push(`${start}`)
    // we finished while going through a range.
    else if (start != (end - 1))
    results.push(`${start}->${end - 1}`)
    return results
};