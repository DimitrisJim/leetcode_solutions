use std::collections::HashSet;

impl Solution {
    pub fn can_form_array(arr: Vec<i32>, pieces: Vec<Vec<i32>>) -> bool {
        let els: HashSet<i32> = arr.iter().cloned().collect();

        for sub in pieces {
            // For 1-element sub-vectors, we only check this.
            // They can be re-organized as required.
            if !els.contains(&sub[0]) {
                return false;
            }
            match sub.len() {
                // So, do nothing here.
                1 => (),
                // For larger sub-vectors, check each element.
                num => {
                    let idx = arr
                        .iter()
                        .position(|x| x == &sub[0])
                        .expect("Arr must contain value.");
                    for j in 1..num {
                        let mut idx_ = idx + j;
                        if idx_ >= arr.len() || arr[idx_] != sub[j] {
                            return false;
                        }
                    }
                }
            }
        }
        true
    }
}
