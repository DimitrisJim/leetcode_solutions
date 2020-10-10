#include <stdlib.h>

int subtractProductAndSum(int n){
    int p = 1;
    int s = 0;
    int rem = 0;
    while (n > 0) {
        rem = n % 10;
        p = p * rem;
        s += rem;
        n /= 10;
    }
    return p - s;
}
