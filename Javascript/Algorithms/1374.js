/**
 * @param {number} n
 * @return {string}
 */
let generateTheString = n => {
    if (n == 1){
        return "a";
    }
    const odd = n & 1;
    let s = "a".repeat(odd? n - 2: n - 1);
    if (odd){
        s += "bc";
    } else {
        s += "b";
    }
    return s;
};
