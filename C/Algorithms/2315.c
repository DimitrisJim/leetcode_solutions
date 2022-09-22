int countAsterisks(char * s){
    int count = 0, flag = 0;
    char c;
    while (c = *s++) {
        if (c == '|') {
            flag ^= 1;
            continue;
        }
        if (c == '*' && !flag)
            count++;
    }
    
    return count;
}