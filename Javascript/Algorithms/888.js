let fairCandySwap = (A, B) => {
    const sumA = A.reduce((acc, x) => acc + x),
          sumB = B.reduce((acc, x) => acc + x),
          a_larger = sumA > sumB;
    
    // Set max, min accordingly.
    const [max, min] = a_larger ? [A, new Set(B)] : [B, new Set(A)],
          diff = Math.floor(a_larger ? (sumA - sumB) / 2: (sumB - sumA) / 2);

    for(let i of max){
        let j = i - diff;
        if (min.has(j)){
            return a_larger? [i, j]: [j, i];
        }
    }
};
