/**
 * @param {string} ransomNote
 * @param {string} magazine
 * @return {boolean}
 */
let canConstruct = (ransomNote, magazine) => {
    const letters = Array(26).fill(0);
    
    // Fill up with counts.
    for (let ch of magazine)
        letters[ch.codePointAt() - 97]++;
    
    // Go through and reduce counts.
    // If at any point count == 0 (and we have encountered value)
    // in ransomNote, bail.
    for(let ch of ransomNote){
        let idx = ch.codePointAt() - 97;
        if (letters[idx]-- == 0)
            return false;
    }
    return true; 
};
