int* sortArrayByParityII(int* A, int ASize, int* returnSize){
    int *res = malloc(ASize * sizeof(*res));
    int evenp = 0, oddp = 1;
    for(int i = 0; i < ASize; i++){
        int value = *(A + i);
        if (value % 2){
            *(res + oddp) = value;
            oddp += 2;
        } else {
            *(res + evenp) = value;
            evenp += 2;
        }
    }
    *returnSize = ASize;
    return res;
}
