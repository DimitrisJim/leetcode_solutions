int arithmeticTriplets(int* nums, int numsSize, int diff){
    int pairs = 0, numdiff;
    
    for(int i = 0; i < numsSize - 2; i++){
        for(int j = i + 1; j < numsSize - 1; j++) {
            numdiff = nums[j] - nums[i];
            if (numdiff > diff)
                break;
            if (numdiff == diff) {
                for(int k = j+1; k < numsSize; k++) {
                    numdiff = nums[k] - nums[j];
                    if (numdiff > diff)
                        break;
                    if (numdiff == diff)
                        pairs++;
                }
            }
        }
    }
    return pairs;
}