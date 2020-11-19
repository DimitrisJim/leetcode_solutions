/**
 * @param {number[]} arr
 * @return {boolean}
 */
var uniqueOccurrences = function(arr) {
    // Build counts of items.
    let counts = new Map;
    for (let i of arr){
        let v = counts.get(i);
        v ? counts.set(i, v+1) : counts.set(i, 1);        
    }
    
    // Create a set to hold values.
    let s = new Set(counts.values());
    
    // sizes are the same?
    return s.size == counts.size
};
