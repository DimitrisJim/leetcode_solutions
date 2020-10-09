/**
 * @param {string} s
 * @param {number[]} indices
 * @return {string}
 */
var restoreString = function(s, indices) {
    let v = Array.from(s);
    for (i = 0; i < s.length; i++){
        v[indices[i]] = s[i];
    }
    return v.join("");
}
