use std::convert::TryFrom;

impl Solution {
    fn best_guess_k(c: i32, n: i32) -> i32 {
        let (mut k, mut ammount) = (0, 0);
        let sumk = Solution::sum_until_k;
        if c <= 100 {
            return k;
        } else if c <= 1000 {
            ammount = 2;
        } else if c <= 100000 {
            ammount = 10;
        } else if c <= 10000000 {
            ammount = 50;
        } else {
            ammount = 250;
        }
        let mut sum = 0;
        loop {
            sum = sumk(k, n);
            if sum < i64::from(c) {
                k += ammount;
            } else {
                k -= ammount;
                break;
            }
        }
        return k;
    }

    fn array_until_k(k: i32, n: i32) -> Vec<i32> {
        let mut vec = Vec::with_capacity(n as usize);
        // we know each value can fit in i32 here. (since candies can.)
        for i in 1..n + 1 {
            vec.push((k + 1) * i + ((k * (k + 1)) >> 1) * n);
        }
        vec
    }

    // Sum needs to be i64, can easily go past i32 range.
    fn sum_until_k(k: i32, n: i32) -> i64 {
        let mut sum: i64 = 0;
        for i in 1..n + 1 {
            sum += i64::from((k + 1) * i + ((k * (k + 1)) >> 1) * n);
        }
        sum
    }

    pub fn distribute_candies(candies: i32, n: i32) -> Vec<i32> {
        let c = candies as i64;
        let (mut prev, mut next) = (0, 0);
        let mut k = Solution::best_guess_k(candies, n);
        let sumk = Solution::sum_until_k;
        while (c >= next) {
            prev = next;
            next = sumk(k, n);
            k += 1;
        }
        if c == next {
            return Solution::array_until_k(k - 1, n);
        }

        let mut left = c - prev;
        k = if k - 2 > 0 { k - 2 } else { 0 };
        let mut result = if prev == 0 {
            k -= 1;
            vec![0; n as usize]
        } else {
            Solution::array_until_k(k, n)
        };

        k = k + 1;
        for i in 1..n + 1 {
            let to_add = ((k + 1) * i + ((k * (k + 1)) >> 1) * n)
                - result[(i - 1) as usize];
            if to_add >= left as i32 {
                result[(i - 1) as usize] += left as i32;
                break;
            }
            result[(i - 1) as usize] += to_add;
            left -= to_add as i64;
        }
        result
    }
}
