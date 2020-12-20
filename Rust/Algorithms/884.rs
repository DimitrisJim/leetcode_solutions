use std::collections::HashSet;

impl Solution {
    pub fn uncommon_from_sentences(a: String, b: String) -> Vec<String> {
        let make_uniques = |A: String| {
            let (mut S, mut Seen) = (HashSet::new(), HashSet::new());
            let v: Vec<String> =
                A.split(" ").map(str::to_string).collect();
            for e in v.into_iter().filter(|w| !w.is_empty()) {
                match Seen.contains(&e) {
                    false => {
                        S.insert(e.clone());
                        Seen.insert(e);
                    }
                    true => {
                        S.remove(&e);
                    }
                }
            }
            (S, Seen)
        };

        let (sA, seenA) = make_uniques(a);
        let (sB, seenB) = make_uniques(b);

        // Cloned to remove all the references.
        let diff1: HashSet<_> = sA.difference(&seenB).cloned().collect();
        let diff2: HashSet<_> = sB.difference(&seenA).cloned().collect();
        diff1.union(&diff2).cloned().collect()
    }
}
