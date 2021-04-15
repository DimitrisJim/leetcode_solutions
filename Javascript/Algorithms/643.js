/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
let findMaxAverage = (nums, k) => {
    const limit = k - 1;
    let partial_avg = 0., max_avg = -1.7976931348623158e+10;

    // Get avg until k-1 
    for (let i = 0; i < limit; i++) {
        partial_avg += nums[i] / k;
    }

    let candidate, last;
    for (let i = limit; i < nums.length; i++) {
        last = nums[i] / k;
        candidate = partial_avg + last;
        if (candidate > max_avg)
            max_avg = candidate;
        // Update partial_avg by removing first term and
        // adding last term (nums[i] / k)
        partial_avg += (last - nums[i - limit] / k);
    }
    return max_avg;
};