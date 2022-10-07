int percentageLetter(char * s, char letter){
    int count = 0, len = 0;
    while (*s) {
        if (*s++ == letter)
            count++;
        len++;
    }
    return (int)(count / (double)len * 100);
}