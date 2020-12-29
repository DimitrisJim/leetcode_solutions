let binaryGap = (n) => {
    if (n <= 2)
        return 0;
    let count = 0, max_dst = 0, start = 0;
    while (n) {
        if (n & 1){
            if (count >= max_dst)
                max_dst = count;
            count = 1;
            start = 1;
        } else {
            if (start){
                count++;
            }
        }
        n >>= 1;
    }
    return max_dst;
};
