int prefixCount(char ** words, int wordsSize, char * pref){
    int count = 0;
    for (int i = 0; i < wordsSize; i++) {
        char *p = pref, *word = words[i];
        while (*p++ == *word++){
            if (*p == '\0'){
                count++;
                break;
            }
        }
    }
    return count;
}