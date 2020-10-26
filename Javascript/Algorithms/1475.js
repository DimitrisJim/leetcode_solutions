/**
 * @param {number[]} prices
 * @return {number[]}
 */
let finalPrices = prices => {
    const length = prices.length
    for(let i=0; i < length - 1; i++){
        let add = true
        let value = prices[i];
        for(let j = i+1; j < length; j++){
            if (prices[j] <= value){
                prices[i] = value - prices[j];
                add = !add;
                break;
            }
        }
        if (add){
            prices[i] = value;
        }
    }
    return prices;
};
