let sortArrayByParity = A => {
    return A.sort((x, y) => ((x & 1) - (y & 1)));
};
