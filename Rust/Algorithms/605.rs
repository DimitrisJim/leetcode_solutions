impl Solution {
    pub fn can_place_flowers(flowerbed: Vec<i32>, n: i32) -> bool {
        let mut n = n as usize;
        let length = flowerbed.len();
        if (n > (length / 2) + (1 * length & 1)) {
            return false;
        }
        if (n == 0) {
            return true;
        }
        if (length == 1) {
            return flowerbed[0] == 0;
        }

        // *Mainly* done so I don't need to special case j == -1
        let mut i = 0;
        if (flowerbed[1] == 0) {
            if (flowerbed[0] == 0) {
                n -= 1;
                if (n == 0) {
                    return true;
                }
                i = 2;
            }
        } else {
            i = 3;
        }

        // Go through the flowerbed array.
        while (i < length) {
            if (flowerbed[i] == 0) {
                let (j, k) = (i - 1, i + 1);
                if (flowerbed[j] == 0) {
                    if (k < length) {
                        if (flowerbed[k] == 0) {
                            n -= 1;
                        } else {
                            i += 3;
                            continue;
                        }
                    } else {
                        return n <= 1;
                    }
                }
                if (n == 0) {
                    return true;
                }
            }
            // Jump by two no matter the case.
            i += 2;
        }
        n == 0
    }
}
