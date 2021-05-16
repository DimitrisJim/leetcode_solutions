use std::cmp::max;

impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        let (mut max_price, mut min_price) = (0, prices[0]);
        for price in prices {
            if (price <= min_price) {
                min_price = price;
            } else {
                max_price = max(max_price, price - min_price);
            }
        }
        max_price
    }
}
