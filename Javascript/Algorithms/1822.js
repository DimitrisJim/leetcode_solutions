/**
 * @param {number[]} nums
 * @return {number}
 */
let arraySign = nums => {
    let res = 1;
    for (let i of nums) {
        if (i == 0)
            return 0;
        if (i < 0)
            res = -res;
    }
    return res;
};