#include <stdlib.h>
#include <stdio.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** flipAndInvertImage(int **A, int ASize, int* AColSize, int* returnSize, int** returnColumnSizes){
    // malloc the array.
    int rowSize = *AColSize;
    int **a = malloc(sizeof(int *) * ASize);
    if (a){
        for (int i = 0; i < ASize; i++){
            a[i] = malloc(sizeof(*a[i]) * rowSize);
        }
    }
    for(int i = 0; i < ASize; i++){
        for(int j = rowSize - 1; j >= 0; j--){
            a[i][(rowSize - 1) - j] = A[i][j] ^ 1;
        }
    }

    *returnSize = ASize;
    *returnColumnSizes = AColSize;

    return a;
}
