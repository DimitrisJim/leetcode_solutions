let decrypt = (code, k) => {
    const result = Array(code.length),
          codeSize = code.length;
    
    if (k == 0){
        result.fill(0);
        return result;
    }
    const K = k > 0? k: -k;
    for(let i = 0; i < codeSize; i++){
        let sum = 0;
        for(let j = 0; j < K; j++){
            if (k > 0)
                sum += code[(i + 1 + j) % codeSize];
            else {
                let idx = i - j - 1;
                sum += code[idx >= 0? idx: codeSize + idx];
            }
        }
        result[i] = sum;
    }
    return result;
};
