/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* decompressRLElist(int* nums, int numsSize, int* returnSize){
    
    int size = 0;
    for (unsigned i = 0; i < numsSize;){
        size += nums[i];
        i += 2;
    }
    int *res = (int *)malloc(sizeof(int) * size);
    /*
    // memory 10.4mb -- 9.49%, 36ms 
    unsigned k = 0, i = 0;
    int fr = nums[0];
    int el = nums[1];
    while (1){
        if (fr == 0){
            k += 2;
            if (k >= numsSize){
                break;
            }
            fr = nums[k];
            el = nums[k+1];
        } else {
            res[i] = el;
            fr -= 1;
            i += 1;
        }
    }
    */
    // same memory 10.4mb -- 9.49%, 32ms -- 81.02% 
    for (unsigned i = 0, z=0; i < numsSize;){
        for (unsigned j = 0; j < nums[i]; j++){
            res[z] = nums[i+1];
            z += 1;
        }
        i = i + 2;
    }
    *returnSize = size;
    return res;
}
