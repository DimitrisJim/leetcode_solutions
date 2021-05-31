impl Solution {
    pub fn count_vowel_strings(n: i32) -> i32 {
        let (mut a, mut e, mut i, mut o) = (5, 4, 3, 1);
        while (o < n) {
            o += 1; i += o + 1; e += i; a += e;
        }
        a
    }
}