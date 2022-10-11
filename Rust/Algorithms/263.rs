impl Solution {
    pub fn is_ugly(mut n: i32) -> bool {
        if n == 0 {
            return false;
        }
        let (primes, mut i) = (vec![2, 3, 5], 0);

        while n != 1 {
            let prime = primes[i];
            if n % prime == 0 {
                n /= prime;
            } else {
                i += 1;
            }
            if i >= 3 {
                return false;
            }
        }
        true
    }
}