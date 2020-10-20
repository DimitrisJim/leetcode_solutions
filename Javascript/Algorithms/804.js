let uniqueMorseRepresentations = words => {
    // Hold array of codes.
    const morse = [
        ".-","-...","-.-.","-..",".","..-.","--.","....",
        "..",".---","-.-",".-..","--","-.","---",".--.","--.-",
        ".-.","...","-","..-","...-",".--","-..-","-.--","--.."
    ];
    // Hold seen code words.
    let seen = new Set;
    for (let word of words){
        // Transform from characters to morse code points.
        const code = Array.from(word).map(
            x => morse[x.codePointAt() - 97]
            ).join("");
        if (!seen.has(code)){
            seen.add(code);
        }
    }
    return seen.size
};
