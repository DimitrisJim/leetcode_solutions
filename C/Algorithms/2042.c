#include <stdbool.h>

bool areNumbersAscending(char * s){
    int previous = 0, next = 0;
    while (*s) {
        int digit = 0;
        while (*s && isdigit(*s)) {
            digit *= 10;
            digit += *s++ - '0';
        }
        if (digit > 0) {
            next = digit;
            if (next <= previous)
                return false;
            previous = next;
            continue;  // don't advance s again.
        }
        s++;
    }
    return true;
}