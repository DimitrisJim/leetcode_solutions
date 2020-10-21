use std::collections::HashSet;

impl Solution {
    pub fn dest_city(mut paths: Vec<Vec<String>>) -> String {
        let (mut sources, mut dests) = (HashSet::new(), HashSet::new());
        for mut v in paths {
            // Move elements out of vector, don't need them there.
            let (dest, source) = (v.pop().unwrap(), v.pop().unwrap());
            sources.insert(source);
            dests.insert(dest);
        }
        dests.difference(&sources).nth(0).unwrap().to_owned()
    }
}
