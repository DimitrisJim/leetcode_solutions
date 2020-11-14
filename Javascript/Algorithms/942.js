/**
 * @param {string} S
 * @return {number[]}
 */
var diStringMatch = function(S) {
    let res = [];
    let i = 0, j = S.length;
    for (let c of S){
        if (c == 'I'){
            res.push(i);
            i++;
        } else {
            res.push(j);
            j--;
        }
    }
    res.push(j);
    return res;
};
