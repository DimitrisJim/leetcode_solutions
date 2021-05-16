/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
  const max = Math.max;
  let max_price = 0, min_price = prices[0];
  for (let price of prices) {
    if (price <= min_price)
      min_price = price;
    else
      max_price = max(max_price, price - min_price);
  }
  return max_price;
};