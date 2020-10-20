#include <string.h>

char * freqAlphabets(char * s){
    // i: indexes the string at current position we're evaluating
    // j: inserting into the string the calculated value
    int i = 0, j = 0;
    int len = strlen(s) + 1;
    while(i < (len - 2)){
        // Handle [char][char]# case
        // Inserting in the string the new character.
        if (*(s + (i + 2)) == '#'){
            char v = *(s + i + 1);
            if (*(s + i) == '1') {
                *(s + j) = 58 + (int)v;
            } else {
                *(s + j) = 68 + (int)v;             
            }
            j++;
            i += 3;
        } 
        // Handle [char] case
        // Insert in the string the new char.
        else {
            *(s + j) = 48 + (int)(*(s+i));
            i++;
            j++;
        }
    }
    // Insert final elements.
    if ((len - i) == 2){
        *(s + j) = 48 + (int)(*(s+i));
        j++;
        *(s + j) = 48 + (int)(*(s+i+1));
        j++;
    } else if ((len - i) == 1){
        *(s + j) = 48 + (int)(*(s+i));
        j++;
    }
    *(s + j - 1) = '\0';
    return s;
}
