let distributeCandies = candyType => {
    const ammount = candyType.length / 2,
          dc = (new Set(candyType)).size;
    return dc < ammount? dc: ammount;
};
