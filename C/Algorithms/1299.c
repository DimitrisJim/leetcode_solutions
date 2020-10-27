/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* replaceElements(int* arr, int arrSize, int* returnSize){
    int len = arrSize - 1;
    int max = *(arr + len);
    *(arr + len) = -1;
    for(int i = len - 1; i > -1; --i){
        int val = *(arr + i);
        *(arr + i) = max;
        max = val > max ? val : max;
    }
    *returnSize = arrSize;
    return arr;
}
