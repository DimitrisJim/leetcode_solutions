/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sumZero(int n, int* returnSize){
    int *arr = malloc(sizeof(int) * n);
    if (!arr)
        return NULL;
    for(int i = 0; i < n - 1; i += 2){
        *(arr+i) = i+1;
        *(arr+i+1) = -(i+1);
    }
    if (n & 1){
        *(arr + n-1) = 0;
    }
    *returnSize = n;
    
    return arr;
}
