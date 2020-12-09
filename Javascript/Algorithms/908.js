let smallestRangeI = (A, K) => {
    let min, max;
    min = max = A[0];
    // Find max and min of A.
    A.forEach( value => {
        if (value < min) {
            min = value;
        }
        if (value > max){
            max = value;
        }
    });
    
    // Find difference.
    let diff = max - K - min;
    if (-K < diff && diff < K){
        return 0;
    }
    return diff > 0 ? diff - K: diff + K;    
};
