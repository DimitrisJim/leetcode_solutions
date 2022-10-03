char repeatedCharacter(char * s){
    int char_set[26] = {0};
    while (*s) {
        if (char_set[*s - 97]) 
            return *s;
        char_set[*s++ - 97]++;
    }
    // unreachable.
    return ' ';
}