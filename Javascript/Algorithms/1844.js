/**
 * @param {string} s
 * @return {string}
 */
let replaceDigits = s => {
  const chr = String.fromCodePoint
  let result = [], i = 1;
  // go through s and shift chars.
  while (i < s.length) {
    let c = s[i - 1], shift = s[i];
    result.push(c);
    // shift('a', '3') => chr(97 + 3) => chr(100) => 'c'
    result.push(chr(c.codePointAt() + (shift - '0')));
    i += 2;
  }
  // if s is of odd length, last char is left alone at end.
  if (s.length & 1) result.push(s[s.length - 1]);

  return result.join('');
};