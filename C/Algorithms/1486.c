int xorOperation(int n, int start){
    int result = start;
    for(unsigned i = 1; i < n; i *= 2)
    {
        result ^= (start + 2 * i);    
    }
    return result;
}
