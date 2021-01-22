/**
 * @param {number[]} A
 * @param {number} K
 * @return {number[]}
 */
let addToArrayForm = (A, K) => {    
    const floor = Math.floor;
    let i = A.length - 1;
    
    while(i >= 0 && K){
        let r = K % 10;
        K = floor(K / 10);
        let sum = A[i] + r;
        if (sum > 9){
            A[i] = sum % 10;
            K++;
        } else 
            A[i] = sum;
        i--;
    }
    
    // Make sure we have nothing else to add.
    if (K > 0){
        let tmp = [];
        while (K){
            let r = K % 10; 
            K = floor(K / 10);
            tmp.push(r);
        }
        return [...tmp.reverse(), ...A];
    }
    return A;
};
