#include <stdbool.h>

bool isPalindrome(char * s){
    int start = 0, end = strlen(s) - 1;
    
    while (start < end) {
        while ((start < end) && !isalnum(s[start]))
            start++;
        while ((start < end) && !isalnum(s[end]))
            end--;
        if (tolower(s[start++]) != tolower(s[end--])) {
            return false;
        }
    }
    return true;    
}