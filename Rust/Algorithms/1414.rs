impl Solution {
    const fibs: [i32; 45] = [
        1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987,
        1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393,
        196418, 317811, 514229, 832040, 1346269, 2178309, 3524578,
        5702887, 9227465, 14930352, 24157817, 39088169, 63245986,
        102334155, 165580141, 267914296, 433494437, 701408733, 1134903170,
    ];

    pub fn find_min_fibonacci_numbers(mut k: i32) -> i32 {
        // Greedy. Always find largest fib number smaller than
        // k and subtract it.
        let fibs = Solution::fibs;
        let (mut count, mut start) = (0, fibs.len() - 1);
        while k >= 0 {
            while k < fibs[start] {
                start -= 1;
                if start == 0 {
                    return count;
                }
            }
            k -= fibs[start];
            count += 1;
        }
        count
    }
}
