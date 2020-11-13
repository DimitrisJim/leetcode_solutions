/**
 * @param {number[]} A
 * @return {number}
 */
let repeatedNTimes = A => {
    let a;
    const length = A.length;
    // Look at triplets. Since (2N - (N+1)) of the elements are the 
    // same, we're bound to find a triplet with two elements. 
    for(let i = 2; i < length; i++){
        a = A[i];
        if ((a == A[i-1]) || (a == A[i-2])){
            return a;
        }
    }
    // Believe it only applies for edge case with 4-elements.
    return a;
};
