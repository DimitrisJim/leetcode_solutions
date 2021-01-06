int maxProfit(int *prices, int pricesSize) {
  // We use action to toggle buying/selling.
  int profit = 0, action = 1, price = 0;

  for (int i = 1; i < pricesSize; i++) {
    int first = *(prices + i - 1), second = *(prices + i);
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
  return action == 0 ? profit + prices[--pricesSize] - price : profit;
}
