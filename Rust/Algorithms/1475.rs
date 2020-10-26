impl Solution {
    pub fn final_prices(mut prices: Vec<i32>) -> Vec<i32> {
        let length = prices.len();
        
        let mut appended;
        for i in 0..length-1 {
            appended = false;
            let val = prices[i];
            for j in i+1..length {
                if prices[j] <= val {
                    prices[i] = val-prices[j];
                    appended = !appended;
                    break;
                }
            }
            if !appended {
                prices[i] = val;
            }
        }
        prices
    }
}
