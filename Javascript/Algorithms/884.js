let uncommonFromSentences = (A, B) => {
    // A - B: Elements in A not in B.
    const difference = (A, B) => {
        const res = new Set;
        for (let e of A){
            if (B.has(e)){
                res.delete(e);
            } else {
                res.add(e);
            }
        }
        return res;
    }
    // A union B.
    const unite = (A, B) => {
        const result = difference(A, B);
        for (let e of difference(B,A)){
            result.add(e);
        }
        return result
    }
    // Create two sets; uniques and seen (i.e not uniques.)
    const build_uniques = A => {
        const S = new Set,
              Seen = new Set;
        if (A){
            for (let w of A.split(' ')){
                if (!Seen.has(w)){
                    S.add(w);
                    Seen.add(w);
                } else {
                    S.delete(w);
                }
            }
        }
        return [S, Seen];
    }
    // Create sets.
    const [sA, seenA] = build_uniques(A);
    const [sB, seenB] = build_uniques(B);
    
    // return (A - seenB) sym_diff (B - seenA)
    let r = unite(difference(sA, seenB), difference(sB, seenA));
    return [...r.values()];
};
