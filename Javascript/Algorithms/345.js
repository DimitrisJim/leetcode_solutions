/**
 * @param {string} s
 * @return {string}
 */
var reverseVowels = function(s) {
  let start = 0, end = s.length - 1;
  const vowels = new Set(...['aeiouAEIOU']), l = [...s];
  while (start < end) {
    while (end > start && !vowels.has(l[end])) end--;
    while (end > start && !vowels.has(l[start])) start++;

    let tmp = l[end];
    l[end--] = l[start];
    l[start++] = tmp;
  }
  return l.join('');
};