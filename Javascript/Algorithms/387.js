/**
 * @param {string} s
 * @return {number}
 */
let firstUniqChar = s => {
    const chars = Array(26).fill(0);
    let idx = 0;
    for (c of s)
        chars[c.codePointAt() - 97]++;
    for (c of s){
        if (chars[c.codePointAt() - 97] == 1)
            return idx;
        idx++;
    }
    return -1;
};
