let tribonacci = n => {
    let a = 0, b = 1, c = 1;
    for (let i = 0; i < n - 2; i++){
        let tmp_a = a, tmp_b = b;
        a = b;
        b = c;
        c = tmp_a + tmp_b + c;
    }
        
    // take care of n == 0 case.
    return n ? c: 0;
};
