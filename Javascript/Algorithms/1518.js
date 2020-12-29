let numWaterBottles = (numBottles, numExchange) => {
    const floor = Math.floor;
    let drinks = numBottles;
    while (1){
        let d = floor(numBottles / numExchange), r = numBottles % numExchange;
        if (d == 0)
            break;
        drinks += d;
        numBottles = d + r;
    }
    return drinks;
};
