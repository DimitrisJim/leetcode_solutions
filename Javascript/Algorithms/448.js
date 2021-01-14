let findDisappearedNumbers = nums => {
    const length = nums.length,
          v = Array(nums.length),
          res = [];
    for (let i = 1; i <= length; i++){
        v[nums[i-1] - 1] = -1;
    }

    nums.forEach((i, idx) => {
        if (v[idx] != -1){
            res.push(idx + 1);
        }
    });
    return res;
};
