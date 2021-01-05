let largestPerimeter = (A) => {
    const lim = A.length - 2;
    A.sort((x, y) => y - x);

    for(let i = 0; i < lim; i++){
        let [a, b, c] = [A[i], A[i+1], A[i+2]];
        if (a + b > c && b + c > a && c + a > b) {
            return a + b + c;
        }
    }
    return 0;
};
