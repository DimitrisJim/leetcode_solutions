#[derive(Debug)]
struct UnionFind {
    parent: Vec<usize>,
    rank: Vec<usize>,
}

impl UnionFind {
    fn with_elements(start: usize, end: usize) -> Self {
        Self {
            parent: (start..end).collect(),
            rank: vec![0; end - start],
        }
    }

    fn find(&mut self, a: usize) -> usize {
        if a == self.parent[a] {
            return a;
        }
        // compress path
        self.parent[a] = self.find(self.parent[a]);
        self.parent[a]
    }

    fn union(&mut self, a: usize, b: usize) {
        let mut a = self.find(a);
        let mut b = self.find(b);
        if a != b {
            if self.rank[a] < self.rank[b] {
                let tmp = a;
                a = b;
                b = tmp;
            }
            self.parent[b] = a;
            if self.rank[a] == self.rank[b] {
                self.rank[a] += 1;
            }
        }
    }
}
