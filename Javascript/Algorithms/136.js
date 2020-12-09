let singleNumber = nums => {
    const xor = (x, y) => x ^ y;
    return nums.reduce(xor);
};
