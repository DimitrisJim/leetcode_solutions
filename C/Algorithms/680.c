#include <stdbool.h>

int cmpdiff(char *s, int *start, int *end) {
    int diff = 0;
    while (*start < *end) {
        if (s[*start] != s[*end]) {
            diff++;
            break;
        }
        (*start)++;
        (*end)--;
    }
    return diff;
}

bool validPalindrome(char * s){
    int start = 0, end = strlen(s) - 1;
    if (cmpdiff(s, &start, &end) == 0)
        return true;
    
    // check the rest:
    int rstart = start+1, rend = end;
    if (cmpdiff(s, &rstart, &rend) == 0)
        return true;
    rstart = start, rend = end-1;
    if (cmpdiff(s, &rstart, &rend) == 0)
        return true;
    return false;
}