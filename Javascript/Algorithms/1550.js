let threeConsecutiveOdds = arr => {
    let count = 0;
    for (let x of arr) {
        count = x & 1 ? count + 1: 0;
        if (count == 3){
            return true;
        }
    }
    return false;
};
