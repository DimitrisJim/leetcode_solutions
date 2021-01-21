earch = (nums, target) => {
    const floor = Math.floor;
    let start = 0, end = nums.length - 1;
    while (start <= end){
        let idx = floor((start + end) / 2),
            mid = nums[idx];
        if (mid == target)
            return idx;
        // go left
        if (target < mid)
            end = idx - 1;
        else
            start = idx + 1;
    }
    return -1;
};
