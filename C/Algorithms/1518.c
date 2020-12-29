int numWaterBottles(int numBottles, int numExchange) {
  int drinks = numBottles;
  while (1) {
    int d = numBottles / numExchange, r = numBottles % numExchange;
    if (d == 0)
      break;
    drinks += d;
    numBottles = d + r;
  }
  return drinks;
}
