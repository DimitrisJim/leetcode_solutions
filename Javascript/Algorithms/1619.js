let trimMean = arr => {
    const length = arr.length,
          sorter = (x, y) => (x - y),
          sum = (acc, v) => acc + v;
    const trim = Number.parseInt(length * 0.05);
    arr.sort(sorter);
    return arr.slice(trim, length-trim).reduce(sum) / (length - 2 * trim);
};
