#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Max size a defanged ipv4 address can have.
#define MAX_DEFANGED 24

char * defangIPaddr(char * address){
    char *res = (char *)malloc((MAX_DEFANGED + 1) * sizeof(char));
    // need them after loop finishes to add '\0'
    size_t i = 0, offset = 0;
    size_t len = strlen(address);
    for(; i < len; i++){
        // add [.] based on offset and increase offset.
        if (ispunct(address[i])) {
            res[i + offset] = '[';
            res[i + offset + 1] = '.';
            res[i + offset + 2] = ']';
            offset += 2;
        } else {
            // add num based on offset.
            res[i + offset] = address[i];
        }
    }
    // add trailing null terminator.
    res[i + offset] = '\0';
    return res;
}

int main(int argc, char **argv) {
    char *addr = "111.111.111.111";
    char * res = defangIPaddr(addr);
    puts(res);
    free(res);
    return 0;
}


