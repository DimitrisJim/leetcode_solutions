/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * unsafe fn guess(num: i32) -> i32 {}
 */

impl Solution {
    // No idea why unsafe is used.
    unsafe fn guessNumber(n: i32) -> i32 {
        let mut start: u32 = 0;
        let mut end: u32 = n as u32;
        loop {
            let mid = (start + end) / 2;
            match guess(mid as i32) {
                0 => break mid as i32,
                1 => start = mid + 1,
                -1 => end = mid,
                _ => panic!(),
            }
        }
    }
}