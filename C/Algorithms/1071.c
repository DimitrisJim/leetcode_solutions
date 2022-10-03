char * gcdOfStrings(char * str1, char * str2){
    char *s = str1, *l = str2;
    if (strlen(s) > strlen(l)) {
        s = str2;
        l = str1;
    }
    
    while (*s && strncmp(l, s, strlen(s)) == 0) {
        int s_len = strlen(s);
        while (strncmp(l, s, s_len) == 0)
            l += s_len;
        char *temp = s;
        s = l;
        l = temp;
    }
    return *s == '\0' ? l : "";
}