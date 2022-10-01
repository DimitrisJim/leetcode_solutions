int countPrefixes(char ** words, int wordsSize, char * s){
    int count = 0;
    for (int i = 0; i < wordsSize; i++) {
        char *st = s, *word = words[i];
        while (*st++ == *word++){
            if (*word == '\0'){
                count++;
                break;
            }
        }
    }
    return count;
}