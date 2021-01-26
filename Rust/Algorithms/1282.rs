use std::collections::HashMap;

impl Solution {
    pub fn group_the_people(group_sizes: Vec<i32>) -> Vec<Vec<i32>> {
        let mut d: HashMap<i32, Vec<_>> = HashMap::new();
        let mut result = vec![];

        for i in 0..group_sizes.len() {
            let group_i = group_sizes[i];
            if group_i == 1 {
                result.push(vec![i as i32]);
                continue;
            }

            match d.get_mut(&group_i) {
                // If we have a group, check to see if it
                // is filled up. If so, add to result.
                // If not, push value into it.
                Some(group) => {
                    if group.len() == (group_i as usize) {
                        result.push(group.to_owned());
                        d.insert(group_i, vec![i as i32]);
                    } else {
                        group.push(i as i32);
                    }
                }
                // If we have no group, create one with i.
                None => {
                    d.insert(group_i, vec![i as i32]);
                }
            }
        }
        // Fill in with values still in d.
        for v in d.values() {
            result.push(v.to_vec());
        }
        result
    }
}
