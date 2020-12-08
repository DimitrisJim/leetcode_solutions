/**
 * @param {string} S
 * @return {string}
 */
let toGoatLatin = S => {
    const vowels = new Set("aAiIeEuUoO"),
          result = [];
    let counter = 1;
    for (let w of S.split(' ')) {
        part = vowels.has(w[0])? w: w.slice(1) + w[0];
        result.push([part, "ma", "a".repeat(counter++)].join(""));
    }
    return result.join(" ");
};
