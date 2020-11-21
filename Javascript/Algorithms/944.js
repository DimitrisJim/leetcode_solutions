/**
 * @param {string[]} A
 * @return {number}
 */
let minDeletionSize = (A) => {
    let indices = new Set,
        rlen = A[0].length,
        len = A.length - 1;
    
    for(let i = 0; i < rlen; i++){
        indices.add(i);
    }
    
    A.reduce((acc, cur) => {
        for(let idx of indices){
            if (cur[idx] < acc[idx]){
                indices.delete(idx);
            }
        }
        return cur;
    })
    return rlen - indices.size;
};
