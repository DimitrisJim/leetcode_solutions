#include <stdbool.h>

bool isPrefixString(char * s, char ** words, int wordsSize){
    for (int i = 0; i < wordsSize; i++){
        char *word = words[i];
        int wordLength = strlen(word);

        // cmp, break if unequal, advance s if equal.
        if (strncmp(s, word, wordLength) != 0)
            break;
        s += wordLength;
    }
    return *s == '\0';
}