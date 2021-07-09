// Note: For UnionFind structure see Structures/UnionFind/uf.rs
impl Solution {
    pub fn find_redundant_connection(edges: Vec<Vec<i32>>) -> Vec<i32> {
        let mut uf = UnionFind::with_elements(0, edges.len() + 1);
        let mut last = vec![];
        for e in edges {
            let (a, b) = (e[0] as usize, e[1] as usize);
            if uf.find(a) == uf.find(b) {
                last = vec![a as i32, b as i32];
            } else {
                uf.union(a, b);
            }
        }
        last
    }
}
