int smallestEvenMultiple(int n){
    return n & 1 ? 2 * n : n;
}