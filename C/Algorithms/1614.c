int maxDepth(char * s){
    int max = 0, depth = 0;
    while (*s){
        if (*s == '('){
            depth++;
            if (depth > max) {
                max = depth;
            }
        } else if (*s == ')'){
            depth--;
        }
        s++;
    }
    return max;
}
