/**
 * @param {character[]} letters
 * @param {character} target
 * @return {character}
 */
let nextGreatestLetter = function(letters, target) {
  if (target >= letters[letters.length - 1]) return letters[0];

  for (let c of letters) {
    if (target < c) return c;
  }
};