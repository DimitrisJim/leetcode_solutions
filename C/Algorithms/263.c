#include <stdbool.h>

bool isUgly(int n){
    if (n == 0)
        return false;
    int primes[3] = {2, 3, 5}, i = 0;
    
    while (n != 1) {
        int prime = primes[i];
        if (n % prime == 0)
            n /= prime;
        else
            i += 1;
        if (i >= 3)
            return false;
    }
    return true;
}