let createTargetArray = (nums, index) => {
    let target = [],
          len = nums.length;
    for (let i = 0; i < len; i++){
        let idx = index[i],
            value = nums[i],
            slice = target.splice(idx);
        
        // Push and add slice back.
        target.push(value);
        target = target.concat(slice);
    }
    return target;
};
