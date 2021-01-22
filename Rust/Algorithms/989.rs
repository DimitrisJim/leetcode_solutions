impl Solution {
    pub fn add_to_array_form(mut a: Vec<i32>, mut k: i32) -> Vec<i32> {
        let mut i = a.len() - 1;

        while k > 0 {
            let r = k % 10;
            k = k / 10;
            let sum = a[i] + r;
            if sum > 9 {
                a[i] = sum % 10;
                k += 1;
            } else {
                a[i] = sum;
            }
            // Need to be careful of usize!
            if i == 0 {
                break;
            }
            i -= 1;
        }

        // Make sure we have nothing else to add.
        if k > 0 {
            let mut tmp = vec![];
            while k > 0 {
                let r = k % 10;
                k = k / 10;
                tmp.push(r);
            }
            tmp = tmp.into_iter().rev().collect();
            tmp.append(&mut a);
            tmp
        } else {
            a
        }
    }
}
