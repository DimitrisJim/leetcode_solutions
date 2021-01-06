impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        // We use action to toggle buying/selling.
        let (mut profit, mut action, mut price) = (0, 1, 0);

        for i in 1..prices.len() {
            let (first, second) = (prices[i - 1], prices[i]);
            // Buying
            if (action == 1) {
                // Only buy at local minimum.
                if (first < second) {
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
        if action == 0 {
            profit + prices.last().unwrap() - price
        } else {
            profit
        }
    }
}
