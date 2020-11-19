/**
 * @param {number[]} position
 * @return {number}
 */
var minCostToMoveChips = function(position) {
    let odds = 0;
    for(let i of position){
        if (i % 2)
            odds++;
    }
    return odds < position.length - odds? odds: position.length - odds;  
};
