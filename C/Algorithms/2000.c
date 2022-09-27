#include "stddef.h"

char * reversePrefix(char * word, char ch){
    char *point = strchr(word, ch);
    if (point == NULL)
        return word;
    
    // swap elements from 0 - diff.
    ptrdiff_t diff = point - word, i = 0;
    while (i < diff) {
        char tmp = word[diff];
        word[diff--] = word[i];
        word[i++] = tmp;
    }

    return word;
}