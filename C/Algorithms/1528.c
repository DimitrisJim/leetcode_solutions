#include <stdlib.h>
#include <stdio.h>

char * restoreString(char * s, int* indices, int indicesSize){
    char *res = (char *)malloc(sizeof(char) * (indicesSize + 1));

    for(unsigned i = 0; i < indicesSize; i++){
        res[indices[i]] = s[i];
    }
    res[indicesSize] = '\0';
    return res;
}


int main(int argc, char **argv){

    char *s = "codeleet";
    int a[8] = {4, 5, 6, 7, 0, 2, 1, 3};
    
    char * res = restoreString(s, a, 8);
    puts(res);
    free(res);

    return 0;
}
