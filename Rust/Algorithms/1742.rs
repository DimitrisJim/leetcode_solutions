impl Solution {
    // Initialize (zeroes) to be able to hold max index
    // sum_digits returns.
    fn init_vector(n: i32) -> Vec<usize> {
        let mut slots = 18;
        if n > 10000 {
            slots = 45;
        } else if n > 1000 {
            slots = 36;
        } else {
            slots = 27;
        }
        vec![0; slots]
    }

    // Return sum of digits in n as usize.
    // used to index count vector.
    #[inline]
    fn sum_digits(mut n: i32) -> usize {
        let mut sum: i32 = 0;
        while n > 0 {
            sum += n % 10;
            n /= 10;
        }
        (sum - 1) as usize
    }

    // Adds to our vector using as a base the given multiple of ten.
    #[inline]
    fn add_from_base(
        v: &mut Vec<usize>,
        n: i32,
        start: usize,
        end: usize,
    ) {
        let base = Solution::sum_digits(n);
        for i in start..end {
            v[base + i] += 1;
        }
    }

    pub fn count_balls(low_limit: i32, high_limit: i32) -> i32 {
        let add_from_base = Solution::add_from_base;
        let mut v = Solution::init_vector(high_limit);

        let (mut start, start_left) = (low_limit / 10, low_limit % 10);
        // note +1. need inclusive.
        let (mut end, end_left) =
            ((high_limit + 1) / 10, (high_limit + 1) % 10);

        // No need to loop, just add [start_left, end_left)
        if start == end {
            add_from_base(
                &mut v,
                start,
                start_left as usize,
                end_left as usize,
            );
        } else {
            // Add start_left, end_left ranges.
            add_from_base(&mut v, start, start_left as usize, 10);
            add_from_base(&mut v, end, 0, end_left as usize);

            // And then go through range [start, end] in multiples of ten.
            // `start` is closest multiple of ten > than low_limit
            // `end` is closest multiple of ten < than high_limit
            start = (start + 1) * 10;
            end = (end - 1) * 10;
            for i in (start..=end).step_by(10) {
                add_from_base(&mut v, i, 0, 10);
            }
        }
        // Return max in v.
        v.into_iter().max().unwrap() as i32
    }
}
