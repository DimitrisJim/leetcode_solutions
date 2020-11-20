/**
 * @param {string} s
 * @return {string}
 */
let reverseWords = (s) => {
    let acc = '';
    s.split(' ').forEach(x => {
        let len = x.length
        for(let i = len - 1; i >= 0; i--){
            // Seems to be best way to build strings.
            acc += x[i];
        }
        acc += ' ';
    });
    // Don't return final space added.
    return acc.slice(0, -1);
};
