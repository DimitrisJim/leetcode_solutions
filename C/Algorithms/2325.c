char * decodeMessage(char * key, char * message){
    int seen[26] = {0}, offsets[26] = {0};
    int offset = 0, space = ' ' - 97;
    
    while (*key) {
        int c = *key++ - 97;
        if (c != space && seen[c] == 0) {
            offsets[c] = offset++;
            seen[c] = 1;
        }
    }

    char *runner = message;
    while (*runner) {
        int c = *runner;
        if (c != ' ') 
            *runner = offsets[c - 97] + 97;
        runner++;
    }
    return message;
}