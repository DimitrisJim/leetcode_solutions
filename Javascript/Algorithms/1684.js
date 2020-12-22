let countConsistentStrings = (allowed, words) => {
    const allowed_set = new Set(allowed);
    console.log(allowed_set);
    let count = 0, flag = 1;
    for (let w of words){
        for (let c of w){
            if (!allowed_set.has(c)) {
                flag = 0;
                break;
            }
        }
        if (!flag){
            flag = 1;
            continue;
        }
        count++;
    }
    return count;
};
