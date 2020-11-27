let sortArrayByParityII = A => {
	// Pre-build Array to hold items.
    let res = Array(A.length);
    let oddp = 1,
        evenp = 0;
 
	// Go through each value in A and place in 
	// correct index.   
    A.forEach((i) => {
        if (i % 2) {
            res[oddp] = i;
            oddp += 2;
        } else {
            res[evenp] = i;
            evenp += 2;
        }
    });
    return res;
};
