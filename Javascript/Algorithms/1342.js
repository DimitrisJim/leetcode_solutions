/**
 * @param {number} num
 * @return {number}
 */
let numberOfSteps  = num => {
    let count = 0;
    while(num){
        if (num & 1){
            num ^= 1;
        } else {
            num>>=1; 
        }
        count += 1;
    }
    return count; 
};
