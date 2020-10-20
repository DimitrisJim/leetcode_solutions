let maxProduct = (nums) => {
    let max = 0, id = 0;
    //  Get first max
    nums.forEach((x, idx) => {
        if (x > max){
            max = x;
            id = idx; 
        }
    });
    let res = max - 1;
    // essentially remove old max
    max = 0;
    nums[id] = -1;
    // find next max.
    nums.forEach(x => {
        if (x > max){
            max = x; 
        }
    });
    return (max - 1) * res;
};
