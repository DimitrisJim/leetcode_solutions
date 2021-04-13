/** Similar logic to Python.
 * @param {string} s
 * @param {number} k
 * @return {string}
 */
let truncateSentence = (s, k) => {
    let i = 0;
    for (let c of s) {
        if (c == ' ')
            k--;
        if (k == 0)
            return s.slice(0, i)
        i++;
    }
    return s;
};