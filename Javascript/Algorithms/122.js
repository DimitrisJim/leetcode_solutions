let maxProfit = prices => {
    const length = prices.length;
    // We use action to toggle buying/selling.
    let profit = 0, action = 1, price = 0;
    
    for(let i = 1; i < length; i++){
        let first = prices[i - 1], 
            second = prices[i];
        // Buying
        if (action == 1){
            // Only buy at local minimum.
            if (first < second){
                price = first;
                action = 0;
            }
        // Selling
        } else {
            // Only sell at local maximum.
            if (first > second) {
                profit += first - price;
                price = 0;
                action = 1;
            }
        }
    }
    // Handle case where we end with a stock still pending to sell.
    return action == 0? profit + prices.pop() - price: profit;
};
