/**
 * @param {number[]} nums
 * @return {number[]}
 */
let frequencySort = nums => {
    // Build frequencies.
    let freqs = new Map;
    for (let i of nums){
        let freq = freqs.get(i);
        if (freq){
            freqs.set(i, freq+1);
        } else {
            freqs.set(i, 1);
        }
    }
    // Move into array & sort things up:
    let vfreqs = Array.from(freqs.entries());
    const firstPass = (x, y) => x[0] - y[0];
    // Actually wrong. Apparently, Firefox's (or whatever
    // is used to run code) JS implementation of sort is stable.
    const secondPass = (x, y) => (y[1] - x[1]);
    vfreqs.sort(firstPass);
    vfreqs.sort(secondPass);
    
    // Build result.
    let result = [],
        length = vfreqs.length;
    for(let i = length-1; i >= 0; i--){
        let [value, freq] = [...vfreqs[i]];
        result.push(...Array.from({length: freq}, () => value));
    }
    return result;
};
