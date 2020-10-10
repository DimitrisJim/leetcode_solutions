/**
 * @param {number[]} nums
 * @return {number[]}
 */
var smallerNumbersThanCurrent = function(nums) {
    // enumerate would get rid of seen.
    let seen = 0;
    let counts = new Map;
    // sort and build counts
    // NOTE: wow, converted to strings and *then* compared..
    for (i of nums.slice().sort((a, b) => (a - b))){
        if (counts.has(i)){
            seen += 1;
        } else {
            counts.set(i, seen);
            seen += 1;
        }
    }
    // create resulting array.
    let res = [];
    for (i of nums) {
        res.push(counts.get(i));
    }
    
    return res;
};
