/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* finalPrices(int* prices, int pricesSize, int* returnSize){
    int added;
    for(int i=0; i < pricesSize -1; i++){
        int value = *(prices + i);
        added = 0;
        for(int j = i+1; j < pricesSize; j++){
            if (*(prices + j) <= value){
                *(prices + i) = value - *(prices + j);
                added = 1;
                break;
            }
        }
        if (added == 0){
            *(prices + i) = value;
        }
    }
    *returnSize = pricesSize;
    return prices;
}
