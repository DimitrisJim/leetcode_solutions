/**
 * @param {number[]} nums
 * @return {number}
 */
let maxAscendingSum = nums => {
    const len = nums.length - 1;
    if (len == 0)
        return nums[0];

    // Keep track of current sum and max found so far.
    let current_sum = 0, max_found = 0;
    for (let i = 0; i < len; i++) {
        let a = nums[i], b = nums[i + 1];
        current_sum += a;
        if (b <= a) {
            // update max if current exceeds it.
            if (current_sum > max_found)
                max_found = current_sum;
            current_sum = 0;
        }
    }

    // Check final value. Either it contributes to current or
    // it is the final value to compare to max_found.
    const final = nums[len];
    if (final > nums[len - 1]) {
        current_sum += final;
        return max_found > current_sum ? max_found : current_sum;
    }
    return max_found > final ? max_found : final;
};