impl Solution {
    pub fn max_product_difference(nums: Vec<i32>) -> i32 {
        // a, b hold 1st and 2nd maxes
        let (mut a, mut b) = (0, 0);
        // c, d hold 1st and 2nd mins
        let (mut c, mut d) = (10 << 10, 10 << 10);
        for num in nums {
            if num >= a {
                let tmp = a;
                a = num;
                b = tmp;
            } else if num > b {
                b = num;
            }
            if num <= c {
                let tmp = c;
                c = num;
                d = tmp;
            } else if num < d {
                d = num;
            }
        }
        a * b - c * d
    }
}
