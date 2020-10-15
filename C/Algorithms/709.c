#include <ctype.h>

// in-place replacement of str.
char * toLowerCase(char * str){
    int i = 0;
    while(*(str + i)){
        *(str+i) = tolower(*(str+i));
        i++;
    };
    return str;
}
