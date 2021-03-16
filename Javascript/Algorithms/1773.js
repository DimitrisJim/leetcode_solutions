/**
 * @param {string[][]} items
 * @param {string} ruleKey
 * @param {string} ruleValue
 * @return {number}
 */
let countMatches = (items, ruleKey, ruleValue) => {
    let index = 0;
    if (ruleKey == 'color'){
        index = 1;
    } else if (ruleKey == 'name')
        index = 2;
    
    let count = 0;
    items.forEach(i => {
        if (i[index] == ruleValue)
            count++;
    });
    return count;
};
