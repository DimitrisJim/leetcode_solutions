#include <stdbool.h>

bool isSameAfterReversals(int num){
    return num == 0 ? true : (num % 10 != 0);
}