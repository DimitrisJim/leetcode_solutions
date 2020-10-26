#include <math.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* selfDividingNumbers(int left, int right, int* returnSize){
    // initial alloc for 10 elements, added counts how many 
    // elements we've added.
    int size = 10, added = 0;
    int *res = malloc(size * sizeof *res);
    if (!res){
        return NULL;
    }
    for(int num = left; num < (right + 1); num++){
        // Count the number of digits in num
        unsigned digits = 0;
        for(int temp = num; temp != 0; digits++, temp /= 10);
    
        // float to int is ok.
        int div = (int) pow(10, digits - 1);
        // Go through digits and see if they divide num.
        int count = 0, red = num;
        while (div) {
            int d = red / div;
            red %= div;
            if ((d != 0) && !(num % d))
                count++;
            else
                break;
            div /= 10;
        }
        // Count == digits, all have divided num
        if (count == digits) {
            if (added >= size){
                // Need to realloc for more memory.
                // geometric increases
                size *= 1.5;
                res = realloc(res, size * sizeof *res);
                if (!res){
                    free(res);
                    return NULL;
                }
            }
            *(res + added++) = num;
        }       
    }
    // Could probably shrink it back to added here.
    *returnSize = added;
    return res;
}
