#include <stdbool.h>

bool checkString(char * s){
    while (*s) {
        if (*s++ == 'b')
            break;
    }
    while (*s) {
        if (*s++ == 'a')
            return false;
    }
    return true;
}