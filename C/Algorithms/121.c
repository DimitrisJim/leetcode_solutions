#define MAX(a, b) a >= b ? a : b

int maxProfit(int *prices, int pricesSize) {
  int max_price = 0, min_price = prices[0];
  for (int i = 0; i < pricesSize; i++) {
    int price = prices[i];
    if (price <= min_price)
      min_price = price;
    else {
      int diff = price - min_price;
      max_price = MAX(max_price, diff);
    }
  }
  return max_price;
}