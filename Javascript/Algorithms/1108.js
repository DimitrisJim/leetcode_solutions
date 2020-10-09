/**
 * @param {string} address
 * @return {string}
 */
var defangIPaddr = function(address) {
    let res = [];
    for (i of address) {
        if (i != '.'){
            res.push(i);
        } else {
            res.push('[.]');
        }
    }
    return res.join('');
};
