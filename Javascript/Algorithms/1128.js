let numEquivDominoPairs = dominoes => {
  let counter = Array(73).fill(0);
  // Defines a (not so perfect) mapping between dominoes to indices.
  const index = (i, j) => (9 * (i - 1)) - i + j;
  dominoes.forEach(([x, y]) => {
    let [i, j] = x > y ? [y, x] : [x, y];
    counter[index(i, j)] += 1;
  });
  let sum = 0;
  counter.filter(x => x).forEach(count => {
    sum += (count * (count - 1));
  })
  return Math.floor(sum / 2);
};