int minBitFlips(int start, int goal){
    int count = 0, b, s;
    if (start > goal) {
        b = start, s = goal;
    } else {
        b = goal, s = start;
    }
    
    while (s) {
        if ((s & 1) != (b & 1))
            count++;
        s >>= 1;
        b >>= 1;
    }
    while (b) {
        if (b & 1)
            count++;
        b >>= 1;
    }
    return count;
}