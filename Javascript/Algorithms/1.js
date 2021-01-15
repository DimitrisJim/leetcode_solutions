let twoSum = (nums, target) => {
    const seen = new Map,
          length = nums.length;
    for (let i = 0; i < length; i++){
        let x = nums[i];
        if (seen.has(target - x)){
            return [i, seen.get(target - x)];
        }
        seen.set(x, i);
    }
};
