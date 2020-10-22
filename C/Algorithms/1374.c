#include <string.h>
#include <stdlib.h>

char * generateTheString(int n){
    if (n == 1){
        return "a";
    }
    // sizeof char == 1
    char *res = malloc(n+1);
    *(res + n) = '\0';
    if(!res)
        return NULL;
    // Fill memory with 'a' until n - 2 or n - 1
    memset(res, 'a', n - (n & 1? 2: 1));
    // Fill in final 2 or 1 positions.
    if (n & 1){
        *(res + n - 2) = 'b';
    }
    *(res + n - 1) = 'c';
    return res;
}
