let hasAlternatingBits = n => {
    while (n){
        let b = n & 1;
        n >>= 1;
        if (b == (n & 1)){
            return false;
        }
    }
    return true;
};
