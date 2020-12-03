let maximumWealth = accounts => {
    const sum = (acc, val) => acc + val,
          max = (x, y) => x > y ? x : y;

    return accounts.map(x => x.reduce(sum)).reduce(max);
};
