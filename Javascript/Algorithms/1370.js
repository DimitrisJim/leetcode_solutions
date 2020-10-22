/**
 * @param {string} s
 * @return {string}
 */
let sortString = s => {
    const sorted = Array.from(new Set(s));
    sorted.sort()
    
    // Early bails
    if (sorted.length == 1){
        return s;
    }
    if (sorted.length == s.length){
        return sorted.join("");
    }
    
    // Create reversed array.
    const reversed = Array.from(sorted);
    reversed.reverse();
    // Build counts.
    const counts = new Map;
    for (let i of s){
        if (counts.has(i)){
            counts.set(i, counts.get(i) + 1);
        } else {
            counts.set(i, 1);
        }
    }
    
    let result = [];
    let [toggle, pending] = [false, true];
    // While counts.size > 1, keep going.
    while (pending){
        let it = toggle ? reversed: sorted;
        for (let i of it){
            if (counts.has(i)){
                let val = counts.get(i);
                // Delete counts[i] if there's only one of it left
                if (val == 1){
                    counts.delete(i)
                    // break 
                    if (counts.size == 1){
                        pending = !pending;
                    }
                // Decrease count
                } else {
                    counts.set(i, val - 1);
                }
                result.push(i);
            }
        }
        toggle = !toggle;
    }
    // Add remaining offset if it exists.
    let offset = "";
    if (counts.size){
        let [char, reps] = counts.entries().next().value;
        offset = char.repeat(reps);
    }
    result = result.join("")
    result += offset;
    return result;
};
