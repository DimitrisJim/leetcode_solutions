let detectCapitalUse = function(word) {
    const length = word.length;
    if (length == 1)
        return true;
    
    const upper = x => x.codePointAt() <= 90,
          lower = x => x.codePointAt() > 96;
    let func = lower, start = 0;    
    if (upper(word[0])){
        if (upper(word[1])){
            func = upper;
        } else {
            start = 1;
        }
    }
    // Basically all.
    for(let i = start; i < length; i++){
        if (!func(word[i]))
            return false;
    }
    return true;
};
