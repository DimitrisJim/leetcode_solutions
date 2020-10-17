#include <stdio.h>

// Create and return new char *.
char * removeOuterParentheses(char * S){
    int i = 0, depth = 0;
    for(; S[i]; i++) ; 
    char *res = (char *)malloc((i + 1) * sizeof(char));
    i = 0;
    while (*S){
        if (*S == '('){
            if (depth >= 1){
                res[i++] = *S;
            }
            depth++;
        } else {
            depth--;
            if (depth >= 1) {
                res[i++] = *S;
            }
        }
        S++;
    }
    // Mark as end.
    res[i] = '\0';
    return res;
}

// Alter S in place with help of other pointer.
char * removeOuterParentheses2(char * S){
    int i = 0, depth = 0;
    char *walker = S;
    while (*walker){
        if (*walker == '('){
            if (depth >= 1)
                S[i++] = *walker;
            depth++;
        } else {
            depth--;
            if (depth >= 1)
                S[i++] = *walker;
        }
        walker++;
    }
    S[i] = '\0';
    return S;
}

int main(int argc, char **argv){
    char *s = "(()())(())";
    char *r = removeOuterParentheses(s);
    printf("%s", r);

    return 0;
}
