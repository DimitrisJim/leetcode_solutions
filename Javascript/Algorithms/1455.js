let isPrefixOfWord = (sentence, searchWord) => {
    let idx = 1;
    for (let x of sentence.split(' ')) {
        if (x.startsWith(searchWord)){
            return idx;
        }
        idx++;
    }
    return -1;
};
