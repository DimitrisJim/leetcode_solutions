let minStartValue = nums => {
    let min = 1, 
        cur = 1;
    for(let i of nums){
        const diff = 1 - (cur + i);
        if (diff > 0) {
            min += diff;
            cur += diff;
        }
        cur += i;
    }
    return min;
};
