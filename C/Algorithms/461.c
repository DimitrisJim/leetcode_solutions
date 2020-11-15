int hammingDistance(int x, int y){
    int diff = x ^ y, count = 0;
    while (diff){
        count += diff & 1; 
        diff >>= 1;
    }
    return count;
}
