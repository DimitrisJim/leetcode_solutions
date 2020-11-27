// Generator to yield each char separately.
function* chain(iterable) {
    for (let sub of iterable) {
        for (let char of sub) {
            yield char;
        }
    }
}

// Compare characters between word1 and word2.
let arrayStringsAreEqual = (word1, word2) => {
    let c1 = chain(word1),
        c2 = chain(word2);  
    
    while (true) {
        let n1 = c1.next(),
            n2 = c2.next();

        if (n1.value != n2.value) {
            return false
        }
        if (n1.done && n2.done){
            return true
        }
    };
};

// alternatively:
let arrayStringsAreEqual_ = (word1, word2) => {
    return word1.join("") == word2.join("");
}
