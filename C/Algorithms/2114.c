int mostWordsFound(char ** sentences, int sentencesSize){
    int max = 0;
    // count spaces per sentence
    for(int i = 0; i < sentencesSize; i++) {
        char *sent = sentences[i];
        int tempmax = 0;
        while(*sent) {
            if (*sent++ == ' ') 
                tempmax++;
        }
        if (tempmax >= max)
            max = tempmax;
    }
    // words = spaces + 1
    return max + 1;
}