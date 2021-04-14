let kLengthApart = (nums, k) => {
    let diff = k,
        first = nums.indexOf(1);
    if (first == -1)
        return true;

    for (let i = first + 1; i < nums.length; i++) {
        if (nums[i]) {
            if (diff > 0)
                return false;
            diff = k;
        } else {
            diff--;
        }
    }
    return true;
};