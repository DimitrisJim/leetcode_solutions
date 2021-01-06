let isMonotonic = A => {
    const length = A.length - 1;
    let decreases = -1;
    for(let i = 0; i < length; i++){
        let a = A[i], b = A[i+1];
        if (a != b){
            if (decreases == -1){
                decreases = a > b;
                continue;
            }
            if ((a > b) != decreases)
                return 0;
        }
    }
    return 1;
};
