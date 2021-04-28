/**
 * @param {string} s
 * @return {string}
 */
var frequencySort = function(s) {
  const counter = new Map;
  for (let c of s) {
    let prev = counter.get(c);
    counter.set(c, prev ? prev + 1 : 1);
  }

  let result = [];
  [...counter.entries()].sort((x, y) => y[1] - x[1]).forEach(([char, count]) => {
    result.push(char.repeat(count));
  });
  return result.join('');
};