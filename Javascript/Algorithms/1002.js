/**
 * @param {string[]} A
 * @return {string[]}
 */
let commonChars = A => {
    // Make counts from the value
    const create_counter = value => {
        let m = new Map;
        for(let i of value) {
            let count = m.get(i);
            m.set(i, count? count + 1: 1);
        }
        return m;
    };
 
    // Replaces common keys in (common, other) with 
    // minimum value of common[key], other[key].   
    const inplace_and = (common, other) => {
        for (let entry of common.entries()){
            let otherval = other.get(entry[0]);
            otherval = otherval? otherval: 0;
            if (otherval < entry[1]){
                common.set(entry[0], otherval);
            }
        }
        for (let entry of common.entries()){
            if (entry[1] == 0){
                common.delete(entry[0]);
            }
        }
        return common
    };
    
	// Initial counts.
    let common = create_counter(A[0]);
    // Find commons.
	A.slice(1).forEach((s) => {
        common = inplace_and(common, create_counter(s));
        // bail early.
        if (common.size == 0){
            return [];
        }
    })
	// Build result and return.
    let result = [];
    for (let e of common.entries()){
        for(let c of e[0].repeat(e[1])){
            result.push(c);
        }
    }
    return result;
};
