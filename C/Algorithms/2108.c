char * firstPalindrome(char ** words, int wordsSize){
    for(int i = 0; i < wordsSize; i++) {
        char *word = words[i];
        int start = 0, end = strlen(word) - 1, found = 1;
        
        while (start < end) {
            if (word[start++] != word[end--]) {
                found = 0;
                break;
            }
        }
        if (found)
            return word;
    }
    return "";
}