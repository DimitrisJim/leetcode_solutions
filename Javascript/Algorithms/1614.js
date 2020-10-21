let maxDepth = s => {
    let depth = 0, max = 0;
    for (let i of s){
        if (i == '('){
            depth++;
            if (depth > max) {
                max = depth;
            }
        }
        if (i == ')'){
            depth--;
        }
    }
    return max;
};
