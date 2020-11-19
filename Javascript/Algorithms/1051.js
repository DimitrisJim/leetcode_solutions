/**
 * @param {number[]} heights
 * @return {number}
 */
var heightChecker = function(heights) {
    // Initialize and sort.
    let target = heights.slice();
    let len = target.length;
    heights.sort((a, b) => a - b);
    
    // Count diffs.
    let diffs = 0;
    for(let i = 0; i < len; i++){
        if (target[i] != heights[i]){
            diffs++;
        }
    }
    return diffs;
};
