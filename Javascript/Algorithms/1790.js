/**
 * @param {string} s1
 * @param {string} s2
 * @return {boolean}
 */
let areAlmostEqual = (s1, s2) => {
    let diff_indices = 0;
    for (let i = 0; i < s1.length; i++) {
        if (s1[i] != s2[i]) {
            diff_indices++;
            if (diff_indices > 2) {
                return false;
            }
        }
    }

    // Set equality, basically.
    const set_s1 = new Set(s1),
        set_s2 = new Set(s2);
    for (let el of set_s1) {
        if (!set_s2.has(el))
            return false;
    }
    if (set_s1.size != set_s2.size)
        return false;
    return true;
};