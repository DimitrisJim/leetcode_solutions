class UnionFind {
  constructor(start, end) {
    this.parent = Array(end - start + 1);
    for (let i = start; i < end; i++) this.parent[i] = i;
    this.rank = Array(this.parent.length).fill(0);
  }

  find(a) {
    let p = this.parent;
    if (a == p[a]) return a;
    // compress path
    p[a] = this.find(p[a]);
    return p[a];
  }

  union(a, b) {
    let rank = this.rank;
    a = this.find(a);
    b = this.find(b);
    if (a != b) {
      if (rank[a] < rank[b]) {
        let tmp = a;
        a = b;
        b = tmp;
      }
      this.parent[b] = a;
      if (rank[a] == rank[b]) rank[a]++;
    }
  }
}
