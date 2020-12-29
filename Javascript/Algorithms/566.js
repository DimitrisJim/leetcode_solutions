let matrixReshape = (nums, r, c) => {
    const rows = nums.length,
          cols = nums[0].length;
    
    if ((r * c) > (rows * cols)){
        return nums;
    }

    const result = [];
    let k = 0, z = 0;  
    // Fill from nums.
    for(let i = 0; i < r; i++){
        let sub = [];
        for (let j = 0; j < c; j++){
            sub.push(nums[k][z++]);
            if (z == cols){
                z = 0;
                k++;
            }
        }
        result.push(sub);
    }
    return result;
};
