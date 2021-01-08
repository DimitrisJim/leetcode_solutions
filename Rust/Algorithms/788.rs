impl Solution {
    const power: u32 = 3;
    const ammounts: [i32; 4] = [0, 4, 40, 316];
    const mirrors: [i32; 26] = [
        1, 8, 10, 11, 18, 80, 81, 88, 100, 101, 108, 110, 111, 118, 180,
        181, 188, 800, 801, 808, 810, 811, 818, 880, 881, 888,
    ];
    // mults stay the same independent from p.
    const mults: [[i32; 2]; 10] = [
        [1, 0],
        [2, 0],
        [2, 1],
        [2, 1],
        [2, 1],
        [2, 2],
        [2, 3],
        [2, 3],
        [3, 3],
        [3, 4],
    ];

    #[inline]
    fn include_mirror_rotations(j: i32) -> i32 {
        let mut count = 1;
        for i in Solution::mirrors.iter() {
            if j < *i {
                break;
            }
            count += 1;
        }
        count
    }

    #[inline]
    fn add_until_previous(v: i32, p: u32) -> i32 {
        let pair = Solution::mults[(v - 1) as usize];
        let (i, j) = (pair[0], pair[1]);
        let prev = Solution::ammounts[p as usize];
        i * prev + j * (prev + (3 as i32).pow(p))
    }

    pub fn rotated_digits(mut N: i32) -> i32 {
        let mut p = Solution::power;
        let (aup, imr) = (
            Solution::add_until_previous,
            Solution::include_mirror_rotations,
        );
        let (mut div, mut good_numbers) = ((10 as i32).pow(p), 0);

        while N != 0 {
            let quot: i32 = N / div;
            N = N % div;
            div /= 10;

            if quot != 0 {
                good_numbers += aup(quot, p);

                match quot {
                    3 | 4 | 7 => {
                        return good_numbers;
                    }
                    2 | 5 | 6 | 9 => {
                        good_numbers += imr(N);
                    }
                    _ => {}
                }
            }
            p -= 1;
        }
        good_numbers
    }
}
