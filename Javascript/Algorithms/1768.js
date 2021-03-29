/**
 * @param {string} word1
 * @param {string} word2
 * @return {string}
 */
let mergeAlternately = (word1, word2) => {
    let control = (word1.length > word2.length) ? word2 : word1;
    const result = [];
    // Interleave until smallers (control)
    for(let i = 0; i < control.length; i++){
        result.push(word1[i]);
        result.push(word2[i]);
    }
    // Push the rest from the max.
    let max = (word1.length > word2.length) ? word1 : word2;
    for(i = control.length; i < max.length; i++){
        result.push(max[i]);
    }
    return result.join("");
};
